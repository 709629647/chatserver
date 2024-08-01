#include "redis.hpp"
#include <thread>
#include <iostream>
using namespace std;
Redis::Redis() : _subscribe_context(nullptr), _publish_context(nullptr)
{
}

Redis::~Redis()
{
    if (_subscribe_context != nullptr)
        redisFree(_subscribe_context);
    if (_publish_context != nullptr)
        redisFree(_subscribe_context);
}

bool Redis::connect()
{
    _subscribe_context = redisConnect("127.0.0.1", 6379);
    if (_subscribe_context == nullptr)
        return false;
    _publish_context = redisConnect("127.0.0.1", 6379);
    if (_publish_context == nullptr)
        return false;
    std::thread t([&]()
                  { observer_channel_message(); });
    t.detach();
    cout << "redis server success" << endl;
    return true;
}

bool Redis::publish(int channel, string message)
{
    redisReply *reply = (redisReply *)redisCommand(_publish_context, "publish %d %s", channel, message.c_str());
    if (reply == nullptr)
    {
        perror("redis pulish err:");
        return false;
    }
    freeReplyObject(reply);
    return true;
}

bool Redis::subscribe(int channel)
{
    if (REDIS_ERR == redisAppendCommand(_subscribe_context, "SUBSCRIBE %d", channel))
    {
        perror("redis subscribe err:");
        return false;
    }
    int done = 0;
    while (!done)
    {
        if (REDIS_ERR == redisBufferWrite(_subscribe_context, &done))
        {
            perror("redis subscribe wirte buff err:");
            return false;
        }
    }
    return true;
}

bool Redis::unsubscribe(int channel)
{
    if (REDIS_ERR == redisAppendCommand(_subscribe_context, "UNSUBSCRIBE %d", channel))
    {
        perror("redis unsubscribe err:");
        return false;
    }
    int done = 0;
    while (!done)
    {
        if (REDIS_ERR == redisBufferWrite(_subscribe_context, &done))
        {
            perror("redis subscribe wirte buff err:");
            return false;
        }
    }
    return true;
}

void Redis::observer_channel_message()
{
    redisReply *reply = nullptr;
    while (REDIS_OK == redisGetReply(_subscribe_context, (void **)&reply))
    {

        if (reply != nullptr && reply->element[2] != nullptr && reply->element[2]->str != nullptr)
        {
            _notify_message_handler(atoi(reply->element[1]->str), reply->element[2]->str);
        }
        freeReplyObject(reply);
    }
}

void Redis::init_notify_handler(function<void(int, string)> fn)
{
    this->_notify_message_handler = fn;
}
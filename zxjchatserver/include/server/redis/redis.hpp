#ifndef REDIS_HPP
#define REDIS_HPP
#include <hiredis/hiredis.h>
#include <string>
#include <functional>
using namespace std;
class Redis
{
private:
    redisContext* _subscribe_context;
    redisContext* _publish_context;
    function <void(int, string)> _notify_message_handler;
public:
    Redis(/* args */);
    ~Redis();
    bool connect();
    bool publish(int channel, string message);
    bool subscribe(int channel);
    bool unsubscribe(int channel);
    void observer_channel_message();
    void init_notify_handler(function<void(int, string)> fn);
};




#endif
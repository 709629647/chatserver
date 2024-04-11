#ifndef CHATSERVICE_H
#define CHATSERVICE_H
#include <unordered_map>
#include <functional>
#include "json.hpp"
#include <mutex>
#include "friendmodel.hpp"
#include "usermodel.hpp"
#include "offlinemessagemodel.hpp"
#include <muduo/net/TcpServer.h>
#include "groupmodel.hpp"
#include "redis.hpp"
using json = nlohmann::json;
using namespace muduo;
using namespace muduo::net;
using namespace std;
using MsgHandler = function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;
class ChatService
{
public:
    static ChatService* getChatServiceInstance();
    void login(const TcpConnectionPtr &conn, json &js, Timestamp);
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp);
    void onechat(const TcpConnectionPtr &conn, json &js, Timestamp);
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp);
    void reset();
    void addfriend(const TcpConnectionPtr &conn, json &js, Timestamp);
    MsgHandler getHandler(int msgid);
    void closeClientException(const TcpConnectionPtr &conn);
    void creategroup(const TcpConnectionPtr &conn, json &js, Timestamp);
    void addgroup(const TcpConnectionPtr &conn, json &js, Timestamp);
    void chatgroup(const TcpConnectionPtr &conn, json &js, Timestamp);
    void handlerRedisSubscribeMessage(int channel, string message);
private:
    ChatService();
    unordered_map<int, MsgHandler> _msgHandlerMap;
    unordered_map<int, TcpConnectionPtr> _connmap;
    mutex _connmutex;
    UserModel _usermodel;
    OfflineMessageModel _offlinemessagemodel;
    FriendModel _friendmodel;
    GroupModel _groupmodel;
    Redis _redis;
};

#endif
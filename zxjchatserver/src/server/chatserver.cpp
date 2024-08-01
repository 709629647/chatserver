#include "chatserver.hpp"
#include "json.hpp"
#include "chatservice.hpp"
#include <functional>
#include "MprpcApplication.h"
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

ChatServer::ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg): _server(loop, listenAddr, nameArg), _loop(loop)
    {
        _server.setConnectionCallback(bind(&ChatServer::onConnect, this, _1));
        _server.setMessageCallback(bind(&ChatServer::onMessage, this, _1, _2, _3));
        _server.setThreadNum(4);
    }

void ChatServer::start()
    {
        _server.start();
    }

void ChatServer::onConnect(const TcpConnectionPtr &conn)
    {
        if (conn->connected())
        {
        }
        else
        {
            ChatService::getChatServiceInstance()->closeClientException(conn);
            conn->shutdown();
        }
    }

void ChatServer::onMessage(const TcpConnectionPtr &conn,
                   Buffer *buffer,
                   Timestamp time)
    {
        string buf = buffer->retrieveAllAsString();
        json js = json::parse(buf);
        MsgHandler handler = ChatService::getChatServiceInstance()->getHandler(js["msgid"].get<int>());
        handler(conn, js, time);
    }
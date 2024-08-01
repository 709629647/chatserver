#pragma once
#include <google/protobuf/service.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <unordered_map>
#include "logger.h"
class MprpcProvider
{
public:
    void NotifyService(::google::protobuf::Service* service);
    void Run();
private:
    muduo::net::EventLoop eventloop_;
    struct ServiceInfo{
        google::protobuf::Service *service_;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> method_map;
    };
    std::unordered_map<std::string, ServiceInfo> serv_map_;
    void OnConnection(const muduo::net::TcpConnectionPtr&);
    void OnMessage(const muduo::net::TcpConnectionPtr&,
                            muduo::net::Buffer*,
                            muduo::Timestamp);
    void SendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message* );
};
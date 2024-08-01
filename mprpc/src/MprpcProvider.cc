#include "MprpcProvider.h"
#include "MprpcApplication.h"
#include <google/protobuf/descriptor.h>
#include "mprpc.pb.h"
#include <google/protobuf/message_lite.h>
#include "zookeeperutils.h"
void MprpcProvider::NotifyService(::google::protobuf::Service *service)
{
    ServiceInfo info;
    const google::protobuf::ServiceDescriptor *serv_des = service->GetDescriptor();
    info.service_ = service;
    std::string serv_name = serv_des->name();
    int m_cnt = serv_des->method_count();
    for (int i = 0; i < m_cnt; ++i)
    {
        const google::protobuf::MethodDescriptor *meth_des = serv_des->method(i);
        info.method_map.insert({meth_des->name(), meth_des});
    }
    serv_map_.insert({serv_name, info});
}

void MprpcProvider::Run()
{
    std::string ip = MprpcApplication::getinstance().getConfig().GetConfigValue("rpcserverip");
    uint16_t port = atoi(MprpcApplication::getinstance().getConfig().GetConfigValue("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);
    muduo::net::TcpServer server(&eventloop_, address, "MprpcProvider");
    server.setConnectionCallback(std::bind(&MprpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&MprpcProvider::OnMessage, this, std::placeholders::_1,
                                        std::placeholders::_2, std::placeholders::_3));
    server.setThreadNum(4);
    ZKClient zk;
    zk.Start();
    for (auto it = serv_map_.begin(); it != serv_map_.end(); ++it)
    {
        char pathname[128] ={0};
        snprintf(pathname, 128, "/%s", it->first.c_str());
        zk.Create(pathname, nullptr, 0);
        std::string pathname_str(pathname);
        // LOGINFO("%s", it->first.c_str());
        for (auto ait = it->second.method_map.begin(); ait != it->second.method_map.end(); ++ait)
        {
            char pathtemp[128] = {0};
            snprintf(pathtemp, 128 , "%s/%s", pathname_str.substr(0, pathname_str.size()).c_str(), ait->first.c_str());
            std::cout << pathtemp << std::endl;
            // snprintf(pathname, 128, "/%s/%s", it->first.c_str(), ait->first.c_str());
            char connstr[32]={0};
            snprintf(connstr, 32, "%s:%u", ip.c_str(), port);
            zk.Create(pathtemp, connstr, strlen(connstr), ZOO_EPHEMERAL);
            // LOGINFO("%s", ait->first.c_str());
        }
    }
    std::cout << ip << " " << port << std::endl;
    server.start();
    eventloop_.loop();
}
void MprpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        conn->shutdown();
    }
}
// head_size  head_str args
// 4bytes
void MprpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn,
                            muduo::net::Buffer *buffer,
                            muduo::Timestamp)
{
    std::string recv_buf = buffer->retrieveAllAsString();
    uint32_t head_size = 0;
    if (recv_buf.copy((char *)&head_size, 4, 0) != 4)
    {
        std::cerr << " copy err";
        return;
    }
    std::string head_str = recv_buf.substr(4, head_size);
    mprpc::Rpc_Header rpc_head;
    if (!rpc_head.ParseFromString(head_str))
    {
        std::cerr << " parse err";
        return;
    }

    std::string args = recv_buf.substr(4 + head_size, rpc_head.args_size());

    std::cout << "================" << std::endl;
    std::cout << head_size << std::endl;
    std::cout << head_str << std::endl;
    std::cout << rpc_head.service_name() << std::endl;
    std::cout << rpc_head.method_name() << std::endl;
    std::cout << rpc_head.args_size() << std::endl;
    std::cout << args << std::endl;
    std::cout << "================" << std::endl;

    auto it = serv_map_.find(rpc_head.service_name());
    if (it == serv_map_.end())
    {
        std::cerr << rpc_head.service_name() << "is not exist";
    }
    auto mit = it->second.method_map.find(rpc_head.method_name());
    if (mit == it->second.method_map.end())
    {
        std::cerr << rpc_head.method_name() << "is not exist";
    }
    google::protobuf::Service *service = it->second.service_;
    const google::protobuf::MethodDescriptor *method_des = mit->second;
    google::protobuf::Message *request = service->GetRequestPrototype(method_des).New();
    if (!request->ParseFromString(args))
    {
        std::cout << "request parse error, content:" << args << std::endl;
        return;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method_des).New();
    google::protobuf::Closure *done = google::protobuf::NewCallback<MprpcProvider, const muduo::net::TcpConnectionPtr &,
                                                                    google::protobuf::Message *>(this, &MprpcProvider::SendRpcResponse, conn, response);
    service->CallMethod(method_des, nullptr, request, response, done);
}

void MprpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn, google::protobuf::Message *response)
{
    std::string response_str;
    if (!response->SerializeToString(&response_str))
    {
        std::cout << "serial err" << std::endl;
    }
    conn->send(response_str);
    conn->shutdown();
}
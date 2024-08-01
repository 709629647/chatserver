#include "MprpcChannel.h"
#include "google/protobuf/message.h"
#include "mprpc.pb.h"
#include <sys/socket.h>
#include <sys/types.h>
#include "MprpcApplication.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "zookeeperutils.h"
// xiliehua dabao
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller, const google::protobuf::Message *request,
                              google::protobuf::Message *response, google::protobuf::Closure *done)
{
    const google::protobuf::ServiceDescriptor *serv_des = method->service();
    std::string service_name = serv_des->name();
    std::string method_name = method->name();
    std::string args = request->SerializeAsString();
    uint32_t args_size = args.size();
    mprpc::Rpc_Header rpc_head;
    rpc_head.set_service_name(service_name);
    rpc_head.set_method_name(method_name);
    rpc_head.set_args_size(args_size);
    std::string head_str = rpc_head.SerializeAsString();
    uint32_t head_size = head_str.size();
    // std::cout << "================" << std::endl;
    // std::cout << head_size << std::endl;
    // std::cout << head_str << std::endl;
    // std::cout << rpc_head.service_name() << std::endl;
    // std::cout << rpc_head.method_name() << std::endl;
    // std::cout << rpc_head.args_size() << std::endl;
    // std::cout << args << std::endl;
    // std::cout << "================" << std::endl;
    
    std::string send_str;
    send_str.insert(0, std::string((char*)&head_size, 4));
    send_str += head_str;
    send_str += args;
    // std::cout << send_str << std::endl;
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    std::string pathname = "/"+service_name +"/" + method_name;
    // std::cout << pathname <<std::endl;
    std::string connstr;
    ZKClient zk;
    zk.Start();
    connstr =  zk.GetData(pathname.c_str());
    // std::cout << connstr <<std::endl;
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    // MprpcConfig config_ = MprpcApplication::getinstance().getConfig();
    // uint16_t port = atoi(config_.GetConfigValue("rpcserverport").c_str());
    // const char *ip = config_.GetConfigValue("rpcserverip").c_str();
    int idx = connstr.find(':');
    const char* ip = connstr.substr(0, idx).c_str();
    uint16_t port = atoi(connstr.substr(idx + 1, connstr.size() - idx - 1).c_str());
    // std::cout <<ip <<" " <<port <<std::endl;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    int ret = connect(clientfd, (sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        controller->SetFailed("conn err");
        close(clientfd);
        return;
    }
    ret = send(clientfd, send_str.c_str(), send_str.size(), 0);
    if (send_str.size() != ret)
    {
        controller->SetFailed("send err");
        close(clientfd);
        return;
    }
    char buf[128] = {0};
    if (-1 == (ret = recv(clientfd, buf, sizeof(buf), 0)))
    {
        controller->SetFailed("recv err");
        close(clientfd);
        return;
    }
    if(!response->ParseFromArray(buf, ret))
        controller->SetFailed("ParseFromArray err");
    close(clientfd);
}
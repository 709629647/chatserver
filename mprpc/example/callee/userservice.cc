#include <iostream>
#include <string>
#include "user.pb.h"
#include "MprpcApplication.h"
#include "logger.h"

class UserService:public fixbug::UserServiceRpc
{
    void Login(std::string name, std::string passwd)
    {
        std::cout <<"login" <<std::endl;
        std::cout << name <<std::endl;
        std::cout << passwd <<std::endl;
    }
    void LoginService(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        //get parameter
        std::string name = request->name();
        std::string pwd = request->pwd();

        //do transaction
        Login(name, pwd);

        //fill back msg
        response->set_success(true);
        response->set_errno_code(0);
        response->set_errmsg("sadasd");
        //do recall
        done->Run();

    }
};

int main(int argc, char** argv)
{
    std::cout << "hello" << std::endl;
    LOGINFO("first msg haha");
    LOGERROR("%s %s %d",__FILE__, __FUNCTION__, __LINE__);
    MprpcApplication::init(argc, argv);
    // std::cout << MprpcApplication::config_.GetConfig("rpcserverip") <<std::endl;
    // std::cout << MprpcApplication::config_.GetConfig("rpcserverport") <<std::endl;
    MprpcProvider provider;
    provider.NotifyService(new UserService);
    provider.Run();
}
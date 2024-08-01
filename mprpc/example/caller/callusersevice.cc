#include "user.pb.h"
#include "MprpcApplication.h"

int main(int argc, char **argv)
{
    MprpcApplication::init(argc, argv);
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    fixbug::LoginRequest request;
    request.set_name("zhangsan");
    request.set_pwd("123456");
    fixbug::LoginResponse response;
    MprpcController contorl;
    stub.LoginService(&contorl, &request, &response, nullptr);
    if (!contorl.Failed())
    {
        if (response.errno_code() == 0)
            std::cout << "login success" << std::endl;
        std::cout << response.errmsg() << std::endl;
    }
    std::cout << contorl.ErrorText() << std::endl;
}
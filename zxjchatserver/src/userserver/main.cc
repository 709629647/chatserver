#include <iostream>
#include <string>
#include "userservice.h"
#include <MprpcApplication.h>
#include <MprpcProvider.h>
int main(int argc, char **argv)
{
    // 调用框架的初始化操作
    MprpcApplication::init(argc, argv);

    // provider是一个rpc网络服务对象。把UserService对象发布到rpc节点上
    MprpcProvider provider;
    provider.NotifyService(new UserService());

    // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}
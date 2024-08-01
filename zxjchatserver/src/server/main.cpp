#include "chatserver.hpp"
#include <iostream>
#include <signal.h>
#include "chatservice.hpp"
#include <MprpcApplication.h>

using namespace std;
void resetHandler(int sig)
{
    ChatService::getChatServiceInstance()->reset();
    exit(0);
}
int main(int argc, char** argv)
{
    signal(SIGINT, resetHandler);
    EventLoop loop;
    MprpcApplication::init(argc, argv);
    MprpcConfig& config = MprpcApplication::getinstance().getConfig();
    // cout << config.GetConfigValue("chatserverip") <<endl;
    // cout << atoi(config.GetConfigValue("chatserverport").c_str())<<endl;
    InetAddress addr(config.GetConfigValue("chatserverip"), atoi(config.GetConfigValue("chatserverport").c_str()));
    
    ChatServer server(&loop, addr, "chatserver");
    cout << "success " <<endl;
    server.start();
    loop.loop();
}
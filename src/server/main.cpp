#include "chatserver.hpp"
#include <iostream>
#include <signal.h>
#include "chatservice.hpp"
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
    InetAddress addr(argv[1], atoi(argv[2]));
    ChatServer server(&loop, addr, "chatserver");
    server.start();
    loop.loop();
}
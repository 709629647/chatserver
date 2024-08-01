#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;
class ChatServer{
    public:
    ChatServer(EventLoop* loop, //事件循环
            const InetAddress& listenAddr,  //ip + port
            const string& nameArg       // server name
            ):_server(loop, listenAddr, nameArg), _loop(loop)
    {
        //给服务器注册用户连接的创建和断开回调
        _server.setConnectionCallback(bind(&ChatServer::onConnection, this, _1));
        //给服务器注册用户读写事件回调
        _server.setMessageCallback(bind(&ChatServer::onMessage, this, _1, _2, _3));

        _server.setThreadNum(4);
    }
    void start()
    {
        _server.start();
    }
    private:
    void onConnection(const TcpConnectionPtr& conn)
    {
        if(conn->connected())
        {
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << " online" <<endl;
        }
        else{
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << "offline" <<endl;
            conn->shutdown();
        }
    }
    void onMessage(const TcpConnectionPtr& conn,
                            Buffer* buf,
                            Timestamp time) //接受信息的事件信息
    {
        string buffer = buf->retrieveAllAsString();
        cout << "recv " << buffer << " at " << time.toString() << endl;
        conn->send(buffer);
    }
    TcpServer _server;
    EventLoop* _loop;
};
// int main()
// {
//     EventLoop loop;
//     InetAddress addr("127.0.0.1", 8989);
//     ChatServer server(&loop, addr, "chatserver");
//     server.start();
//     loop.loop();
// }
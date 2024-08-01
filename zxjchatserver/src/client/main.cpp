#include "json.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <functional>
#include <MprpcApplication.h>
using namespace std;
using json = nlohmann::json;

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <semaphore.h>
#include <atomic>

#include "group.hpp"
#include "user.hpp"
#include "public.hpp"

User g_curruser(-1);
vector<User> g_friendlist;

vector<Group> g_grouplist;
sem_t sem;
atomic_bool islogintrue{false};
bool MainMenuIsRunning = false;
void mainMenu(int clientfd);
// "help" command handler
void help(int fd = 0, string str = "");
// "chat" command handler
void chat(int, string);
// "addfriend" command handler
void addfriend(int, string);
// "creategroup" command handler
void creategroup(int, string);
// "addgroup" command handler
void addgroup(int, string);
// "groupchat" command handler
void groupchat(int, string);
// "loginout" command handler
void loginout(int, string);
void friendlist(int, string);
void grouplist(int, string);
// 系统支持的客户端命令列表
unordered_map<string, string> commandMap = {
    {"help", "显示所有支持的命令，格式help"},
    {"chat", "一对一聊天，格式chat:friendid:message"},
    {"addfriend", "添加好友，格式addfriend:friendid"},
    {"creategroup", "创建群组，格式creategroup:groupname:groupdesc"},
    {"addgroup", "加入群组，格式addgroup:groupid"},
    {"groupchat", "群聊，格式groupchat:groupid:message"},
    {"friendlist", "查看好友列表，格式friendlist"},
    {"groupist", "查看群列表，格式grouplist"},
    {"loginout", "注销，格式loginout"}};

// 注册系统支持的客户端命令处理
unordered_map<string, function<void(int, string)>> commandHandlerMap = {
    {"help", help},
    {"chat", chat},
    {"addfriend", addfriend},
    {"creategroup", creategroup},
    {"addgroup", addgroup},
    {"groupchat", groupchat},
    {"friendlist", friendlist},
    {"grouplist", grouplist},
    {"loginout", loginout}};
void readHandler(int fd);
void showCurrentUserData();
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        perror("argc < 3");
        exit(EXIT_FAILURE);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);
    sockaddr_in server;
    memset(&server, 0, sizeof(sockaddr_in));
    socklen_t len = sizeof(server);
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    int ret = connect(clientfd, (sockaddr *)&server, len);
    sem_init(&sem, 0, 0);
    std::thread readthread(readHandler, clientfd);
    readthread.detach();
    if (ret < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        // 显示首页面菜单 登录、注册、退出
        cout << "========================" << endl;
        cout << "1. login" << endl;
        cout << "2. register" << endl;
        cout << "3. quit" << endl;
        cout << "========================" << endl;
        cout << "choice: ";
        int choice = 0;
        cin >> choice;
        getchar();
        switch (choice)
        {
        case 1:
        {
            int id;
            char password[20];
            json request;
            cout << "input your id: ";
            cin >> id;
            getchar();
            cout << "input your password: ";
            cin.getline(password, 20);
            request["msgid"] = LoginType;
            request["id"] = id;
            request["password"] = password;

            string js = request.dump();

            int size = strlen(js.c_str()) + 1;
            int len = send(clientfd, js.c_str(), size, 0);
            if (len < 0)
            {
                perror("register recv err");
                exit(EXIT_FAILURE);
            }
            sem_wait(&sem);
            cout << islogintrue<<endl;
            if (islogintrue)
            {
                MainMenuIsRunning = true;
                mainMenu(clientfd);
            }
            else
            {
                perror("login failed");
            }
            break;
        }
        case 2:
        {
            char name[20];
            char password[20];
            cout << "input your name" << endl;
            cin.getline(name, 20);
            cout << "input your password" << endl;
            cin.getline(password, 20);
            json request;
            request["msgid"] = RegType;
            request["name"] = name;
            request["password"] = password;
            string js = request.dump();
            int size = strlen(js.c_str()) + 1;
            int len = send(clientfd, js.c_str(), size, 0);
            if (len < size)
            {
                perror("register recv err");
            }
            sem_wait(&sem);
            break;
        }

        case 3:
            close(clientfd);
            exit(0);
            break;
        default:
            break;
        }
    }
}
void doRegisterResponse(json &respond)
{
    if (respond["errno"].get<int>() == 0)
    {
        cout << "register successful" << endl;
        cout << "your id is" << respond["id"] << endl;
    }
    else
    {
        perror("register failed");
    }
    sem_post(&sem);
}
void doLoginResponse(json &respond)
{
    cout << respond["errno"].get<int>()<<endl;
    if (respond["errno"].get<int>() == 0)
    {
        g_curruser.setid(respond["id"].get<int>());
        g_curruser.setname(respond["name"]);
        islogintrue = true;
        if (respond.contains("friendlist"))
        {
            g_friendlist.clear();
            vector<string> list = respond["friendlist"];
            for (auto &_friend1 : list)
            {
                json _friend = json::parse(_friend1);
                User user(_friend["id"].get<int>(), _friend["name"], "", _friend["state"]);
                g_friendlist.push_back(user);
            }
        }
        if (respond.contains("group"))
        {
            g_grouplist.clear();
            vector<string> groups = respond["group"];
            for (auto &_group1 : groups)
            {
                json _group = json::parse(_group1);
                Group group(_group["id"].get<int>(), _group["groupname"], _group["groupdesc"]);
                vector<string> vecuser = _group["users"];
                for (auto &_user1 : vecuser)
                {
                    json _user = json::parse(_user1);
                    GroupUser user(_user["id"], _user["name"], "", _user["state"], _user["role"]);
                    group.getgroupuser().push_back(std::move(user));
                }
                g_grouplist.push_back(std::move(group));
            }
        }
        showCurrentUserData();
        if (respond.contains("offlinemsg"))
        {

            vector<string> offlinemsg = respond["offlinemsg"];
            for (auto &_msg : offlinemsg)
            {
                json msg = json::parse(_msg);
                int type = msg["msgid"];
                if (type == OneChatType)
                {
                    cout << msg["time"].get<string>() << " [" << msg["id"] << "] " << msg["from"] << " said: "
                         << msg["msg"] << endl;
                }
                else
                {
                    cout << "群消息[" << msg["groupid"] << "]:" << msg["time"].get<string>() << " [" << msg["id"] << "]" << msg["name"]
                         << " said: " << msg["msg"] << endl;
                }
            }
        }
        
    }

    sem_post(&sem);
}
void readHandler(int fd)
{
    for (;;)
    {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int len = recv(fd, buf, 1024, 0);
        if (len < 0)
        {
            perror("read err");
            exit(EXIT_FAILURE);
        }
        // cout << buf<<endl;
        json js = json::parse(string(buf));
        int type = js["msgid"].get<int>();
        // cout << type <<endl;
        if (type == OneChatType)
        {
            cout << js["time"].get<string>() << " [" << js["id"] << "] " << js["from"] << " said: "
                 << js["msg"] << endl;
        }
        else if (type == ChatGroupType)
        {
            cout << "群消息[" << js["groupid"] << "]:" << js["time"].get<string>() << " [" << js["id"] << "]" << js["name"].get<string>()
                 << " said: " << js["msg"].get<string>() << endl;
            continue;
        }
        else if (type == LogAckType)
        {
            doLoginResponse(js);
        }
        else if (type == RegAckType)
            doRegisterResponse(js);
        else if (type == AddFriendAckType)
        {

            if (js["errno"].get<int>() != 0)
                perror("get fault back");
            else
                g_friendlist.push_back(User(js["id"].get<int>(), js["name"], "", js["state"]));
            sem_post(&sem);
        }
        else if (type == ChatAckType)
        {
            if (js["errno"].get<int>() != 0)
                perror("get fault back");
            sem_post(&sem);
        }
        else if (type == CreateGroupAckType)
        {

            if (js["errno"].get<int>() != 0)
                perror("get fault back");
            else
                g_grouplist.push_back(Group(js["groupid"], js["groupname"], js["groupdesc"]));
            sem_post(&sem);
        }
        else if (type == AddGroupAckType)
        {
            // cout << js.dump() <<endl;
            if (js["errno"].get<int>() != 0)
            {
                perror("get fault back");
            }
            else
                g_grouplist.push_back(Group(js["groupid"], js["groupname"], js["groupdesc"]));
            sem_post(&sem);
        }
        else if (type == ChatGroupAckType)
        {
            if (js["errno"].get<int>() != 0)
                perror("get fault back");
            sem_post(&sem);
        }
    }
}
void showCurrentUserData()
{
    cout << "======================login user======================" << endl;
    cout << "current login user => id:" << g_curruser.getid() << " name:" << g_curruser.getname() << endl;
    cout << "----------------------friend list---------------------" << endl;
    if (!g_friendlist.empty())
    {
        for (User &user : g_friendlist)
        {
            cout << user.getid() << " " << user.getname() << " " << user.getstate() << endl;
        }
    }
    cout << "----------------------group list----------------------" << endl;
    if (!g_grouplist.empty())
    {
        for (Group &group : g_grouplist)
        {
            cout << "群组号：" << group.getgroupid() << " " << group.getgroupname() << " " << group.getgroupdesc() << endl;
            for (GroupUser &user : group.getgroupuser())
            {
                cout << "用户号：" << user.getid() << " " << user.getname() << " " << user.getstate()
                     << " " << user.getrole() << endl;
            }
        }
    }
    cout << "======================================================" << endl;
}

void mainMenu(int clientfd)
{
    help();

    char buffer[1024] = {0};
    while (MainMenuIsRunning)
    {
        cin.getline(buffer, 1024);
        string commandbuf(buffer);
        string command; // 存储命令
        int idx = commandbuf.find(":");
        if (-1 == idx)
        {
            command = commandbuf;
        }
        else
        {
            command = commandbuf.substr(0, idx);
        }
        auto it = commandHandlerMap.find(command);
        if (it == commandHandlerMap.end())
        {
            cerr << "invalid input command!" << endl;
            continue;
        }

        // 调用相应命令的事件处理回调，mainMenu对修改封闭，添加新功能不需要修改该函数
        it->second(clientfd, commandbuf.substr(idx + 1, commandbuf.size() - idx)); // 调用命令处理方法
    }
}
void help(int, string)
{
    cout << "show command list >>> " << endl;
    for (auto &p : commandMap)
    {
        cout << p.first << " : " << p.second << endl;
    }
    cout << endl;
}
void addfriend(int fd, string str)
{
    int friendid = atoi(str.c_str());
    int id = g_curruser.getid();
    json js;
    js["id"] = id;
    js["friendid"] = friendid;
    js["msgid"] = AddFriendType;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("chat send err:");
    sem_wait(&sem);
}

void chat(int fd, string str)
{
    int idx = str.find(":"); // friendid:message
    if (-1 == idx)
    {
        cerr << "chat command invalid!" << endl;
        return;
    }

    int friendid = atoi(str.substr(0, idx).c_str());
    string message = str.substr(idx + 1, str.size() - idx);
    json js;
    js["msgid"] = OneChatType;
    js["id"] = g_curruser.getid();
    js["from"] = g_curruser.getname();
    js["to"] = friendid;
    js["msg"] = message;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("chat send err:");
    sem_wait(&sem);
}
void creategroup(int fd, string str)
{
    int idx = str.find(":"); // friendid:message
    if (-1 == idx)
    {
        cerr << "chat command invalid!" << endl;
        return;
    }
    string groupname = str.substr(0, idx);
    string groupdesc = str.substr(idx + 1, str.size() - idx);
    json js;
    js["id"] = g_curruser.getid();
    js["groupname"] = groupname;
    js["groupdesc"] = groupdesc;
    js["msgid"] = CreateGroupType;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("chat send err:");

    sem_wait(&sem);
}
// "addgroup" command handler
void addgroup(int fd, string str)
{
    
    int groupid = atoi(str.c_str());
    int id = g_curruser.getid();
    json js;
    js["id"] = id;
    js["groupid"] = groupid;
    js["msgid"] = AddGroupType;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("addgroup err:");
    sem_wait(&sem);
}
// "groupchat" command handler
void groupchat(int fd, string str)
{
    int idx = str.find(":"); // friendid:message
    if (-1 == idx)
    {
        cerr << "chat command invalid!" << endl;
        return;
    }

    int groupid = atoi(str.substr(0, idx).c_str());
    string message = str.substr(idx + 1, str.size() - idx);
    json js;
    js["msgid"] = ChatGroupType;
    js["id"] = g_curruser.getid();
    js["name"] = g_curruser.getname();
    js["groupid"] = groupid;
    js["msg"] = message;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("chat send err:");
    sem_wait(&sem);
}
// "loginout" command handler
void loginout(int fd, string str)
{
    json js;
    js["id"] = g_curruser.getid();
    js["msgid"] = LoginOutType;
    MainMenuIsRunning = false;
    string request = js.dump();
    if (send(fd, request.c_str(), strlen(request.c_str()) + 1, 0) < 0)
        perror("chat send err:");
    // char buf[128] = {0};
    // int len = recv(fd, buf, 128, 0);
    // if(len < 0)
    //     perror("chat recv err:");
    // json response = json::parse(string(buf));
    // if(response["msgid"].get<int>() != LoginoutAckType || response["errno"].get<int>() != 0)
    //     perror("get fault back:");
}

void friendlist(int fd, string str)
{
    cout << "id号   "
         << "name  "
         << "state   " << endl;
    for (auto &_friend : g_friendlist)
    {
        cout << _friend.getid() << "  " << _friend.getname() << " " << _friend.getstate() << endl;
    }
}

void grouplist(int fd, string str)
{
    cout << "群号   "
         << "群名  "
         << "群简介   " << endl;
    for (auto &_group : g_grouplist)
    {
        cout << _group.getgroupid() << "  " << _group.getgroupname() << " " << _group.getgroupdesc() << endl;
    }
}
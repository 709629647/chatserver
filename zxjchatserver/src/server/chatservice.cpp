#include "chatservice.hpp"
#include "public.hpp"
#include <vector>
#include "muduo/base/Logging.h"
#include "chat.pb.h"
#include <MprpcApplication.h>
ChatService::ChatService()
{
    this->_msgHandlerMap.insert({LoginType, bind(&ChatService::login, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({RegType, bind(&ChatService::reg, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({OneChatType, bind(&ChatService::onechat, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({AddFriendType, bind(&ChatService::addfriend, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({CreateGroupType, bind(&ChatService::creategroup, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({AddGroupType, bind(&ChatService::addgroup, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({ChatGroupType, bind(&ChatService::chatgroup, this, _1, _2, _3)});
    this->_msgHandlerMap.insert({LoginOutType, bind(&ChatService::loginout, this, _1, _2, _3)});
    if (_redis.connect())
    {
        _redis.init_notify_handler(bind(&ChatService::handlerRedisSubscribeMessage, this, _1, _2));
    }
}
MsgHandler ChatService::getHandler(int msgid)
{
    if (_msgHandlerMap.find(msgid) == _msgHandlerMap.end())
    {
        return [msgid](const TcpConnectionPtr &conn, json &js, Timestamp time)
        {
            LOG_ERROR << "msgid : " << msgid << "can not find";
        };
    }
    else
        return _msgHandlerMap[msgid];
}

void ChatService::reset()
{
    _usermodel.resetState();
}
void ChatService::addfriend(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    int userid = js["id"].get<int>();
    int friendid = js["friendid"].get<int>();
    user::UserServiceRpc_Stub stub(new MprpcChannel());
    user::AddFriendRequest request;
    request.set_userid(userid);
    request.set_friendid(friendid);
    user::AddFriendResponse user_response;
    MprpcController controller;
    stub.AddFriend(&controller, &request, &user_response, nullptr);
    if(controller.Failed())
    {
        cout << controller.ErrorText() << endl;
    }
    json response;
    response["msgid"] = AddFriendAckType;
    response["errno"] = user_response.errcode();
    response["id"] = friendid;
    response["name"] = user_response.name();
    response["state"] = user_response.state();
    response["errmsg"]  = user_response.errmsg();
    conn->send(response.dump());
}
ChatService *ChatService::getChatServiceInstance()
{
    static ChatService chatservice;
    return &chatservice;
}
void ChatService::login(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    int id = js["id"].get<int>();
    string password = js["password"];
    User user = _usermodel.query(id);
    json response;
    if (user.getid() != -1 && user.getpassword() == password)
    {
        if (user.getstate() == "online")
        {
            response["msgid"] = LogAckType;
            response["errno"] = 2;
            response["errmsg"] = "用户重复登录";
        }
        else
        {
            {
                lock_guard<mutex> lock(_connmutex);
                _connmap.insert({id, conn});
            }
            
            _redis.subscribe(id);
            user.setstate("online");
            _usermodel.updateState(user);
            response["msgid"] = LogAckType;
            response["errno"] = 0;
            response["id"] = user.getid();
            response["name"] = user.getname();
            vector<string> vec(_offlinemessagemodel.query(id));
            if (!vec.empty())
            {
                response["offlinemsg"] = vec;
                _offlinemessagemodel.remove(id);
            }
            vec.clear();
            vector<User> vec2 = _friendmodel.query(id);

            if (!vec2.empty())
            {
                vector<string> vecstr;
                for (auto &user : vec2)
                {
                    json jsuser;
                    jsuser["id"] = user.getid();
                    jsuser["name"] = user.getname();
                    jsuser["state"] = user.getstate();
                    vecstr.push_back(jsuser.dump());
                }
                response["friendlist"] = vecstr;
            }
            vector<Group> vec3(_groupmodel.queryGroup(user.getid()));
            if (!vec3.empty())
            {
                vector<string> vecstr;
                for (auto &group : vec3)
                {
                    json grpjson;
                    grpjson["id"] = group.getgroupid();
                    grpjson["groupname"] = group.getgroupname();
                    grpjson["groupdesc"] = group.getgroupdesc();
                    vector<string> userV;
                    for (GroupUser &user : group.getgroupuser())
                    {
                        json js;
                        js["id"] = user.getid();
                        js["name"] = user.getname();
                        js["state"] = user.getstate();
                        js["role"] = user.getrole();
                        userV.push_back(js.dump());
                    }
                    grpjson["users"] = userV;
                    vecstr.push_back(grpjson.dump());
                }
                response["group"] = vecstr;
            }
        }
    }
    else
    {
        response["msgid"] = LogAckType;
        response["errno"] = 3;
        response["errmsg"] = "没有此用户或者用户密码错误";
    }
    conn->send(response.dump());
}

void ChatService::reg(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    string name = js["name"];
    string password = js["password"];
    User user(-1, name, password);

    bool state = _usermodel.insert(user);
    json response;
    if (state)
    {
        response["msgid"] = RegAckType;
        response["errno"] = 0;
        response["id"] = user.getid();
    }
    else
    {
        response["msgid"] = RegAckType;
        response["errno"] = 1;
        response["errmsg"] = "register failed!";
    }
    conn->send(response.dump());
}

void ChatService::closeClientException(const TcpConnectionPtr &conn)
{
    User user;
    {
        lock_guard<mutex> lock(_connmutex);
        for (auto it = _connmap.begin(); it != _connmap.end(); ++it)
        {
            if (it->second == conn)
            {
                user.setid(it->first);
                _connmap.erase(it);
                break;
            }
        }
    }
    if (user.getid() != -1)
    {
        _redis.unsubscribe(user.getid());
        user.setstate("offline");
        _usermodel.updateState(user);
    }
}

void ChatService::loginout(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    int id = js["id"].get<int>();
    {
        lock_guard<mutex> lock(_connmutex);
        auto it = _connmap.find(id);
        if (it != _connmap.end())
        {
            _connmap.erase(it);
        }
    }
    _redis.unsubscribe(id);
    User user(id, "", "", "offline");
    _usermodel.updateState(user);
}

void ChatService::onechat(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    string from = js["from"];
    int to_id = js["to"].get<int>();
    string message = js["msg"];
    js["time"] = time.toFormattedString();
    User user = _usermodel.query(to_id);
    if (user.getid() == to_id)
    {
        {
            lock_guard<mutex> lock(_connmutex);
            auto it = _connmap.find(to_id);
            if (it != _connmap.end())
            {
                json response;
                response["msgid"] = ChatAckType;
                response["errno"] = 0;

                // response.insert(js.begin(), js.end());
                // response["from"] = name;
                // response["to_id"] = to_id;
                // response["msg"] = message;
                conn->send(response.dump());
                it->second->send(js.dump());
                return;
            }
        }

        if (_usermodel.query(to_id).getstate() == "online")
        {
            
            
            json response;
            response["msgid"] = ChatAckType;
            response["errno"] = 0;
            conn->send(response.dump());
            // std::cout << js.dump() << endl;
            _redis.publish(to_id, js.dump());
            return;
        }
        OfflineMessage offlinemessage(to_id, js.dump());
        if (_offlinemessagemodel.insert(offlinemessage))
        {
            json response;
            response["msgid"] = ChatAckType;
            response["errno"] = 0;

            conn->send(response.dump());
            return;
        }

        json response;
        response["msgid"] = ChatAckType;
        response["errno"] = 2;
        response["errmsg"] = "offlinemessage send err!";
        conn->send(response.dump());
        return;
    }
    else
    {
        json response;
        response["msgid"] = ChatAckType;
        response["errno"] = 1;
        response["errmsg"] = "this id does not exist!";
    }
}

void ChatService::creategroup(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    int id = js["id"].get<int>();
    string groupname = js["groupname"];
    string groupdesc = js["groupdesc"];
    user::UserServiceRpc_Stub stub(new MprpcChannel());
    user::CreateGroupRequest request;
    request.set_userid(id);
    request.set_groupname(groupname);
    request.set_groupdesc(groupdesc);
    user::CreateGroupResponse user_response;
    MprpcController controller;
    stub.CreateGroup(&controller, &request, &user_response, nullptr);
    if(controller.Failed())
    {
        cout << controller.ErrorText() << endl;
    }
    json response;
    response["msgid"] = CreateGroupAckType;
    response["errno"] = user_response.errcode();
    response["groupid"] = user_response.groupid();
    response["groupname"] = user_response.groupname();
    response["groupdesc"] = user_response.groupdesc();
    conn->send(response.dump());
}

void ChatService::addgroup(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    int id = js["id"].get<int>();
    string role = "normal";
    int groupid = js["groupid"].get<int>();
    user::UserServiceRpc_Stub stub(new MprpcChannel());
    user::AddGroupRequest request;
    request.set_id(id);
    request.set_groupid(groupid);
    request.set_role(role);
    json response;
    user::AddGroupResponse user_response;
    MprpcController controller;
    stub.AddGroup(&controller, &request, &user_response, nullptr);
    if(controller.Failed())
    {
        cout << controller.ErrorText() << endl;
    }
    response["msgid"] = AddGroupAckType;
    response["errno"] = user_response.errcode();
    response["groupid"] = user_response.groupid();
    response["groupname"] = user_response.groupname();
    response["groupdesc"] = user_response.groupdesc();
    conn->send(response.dump());
    
}
void ChatService::chatgroup(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    int id = js["id"].get<int>();
    int groupid = js["groupid"].get<int>();
    js["time"] = time.toFormattedString();
    vector<int> vec(_groupmodel.queryGroupUser(id, groupid));
    lock_guard<mutex> lock(_connmutex);
    for (int i = 0; i < vec.size(); ++i)
    {
        auto it = _connmap.find(vec[i]);
        if (it != _connmap.end())
        {
            json response;
            response["msgid"] = ChatGroupAckType;
            response["errno"] = 0;

            it->second->send(js.dump());
            conn->send(response.dump());
            return;
        }
        else if (_usermodel.query(vec[i]).getstate() == "online")
        {
            _redis.publish(vec[i], js.dump());
            json response;
            response["msgid"] = ChatGroupAckType;
            response["errno"] = 0;
            conn->send(response.dump());
            return;
        }
        else
        {
            json response;
            response["msgid"] = ChatGroupAckType;
            response["errno"] = 0;

            OfflineMessage msg(vec[i], js.dump());
            _offlinemessagemodel.insert(msg);
            conn->send(response.dump());
        }
    }
    json response;
    response["msgid"] = ChatGroupAckType;
    response["errno"] = 0;
    conn->send(response.dump());
}

void ChatService::handlerRedisSubscribeMessage(int channel, string message)
{

    {
        lock_guard<mutex> lock(_connmutex);
        auto it = _connmap.find(channel);
        if(it != _connmap.end())
        {
            it->second->send(message);
            return;
        }
    }
    OfflineMessage offline(channel, message);
    _offlinemessagemodel.insert(offline);
}
#include "userservice.h"
string UserService::addfriend(uint32_t userid, uint32_t friendid)
{
    // int userid = js["id"].get<int>();
    // int friendid = js["friendid"].get<int>();
    string returnval = "";

    if (_friendmodel.insert(userid, friendid))
    {
        User user = _usermodel.query(friendid);
        returnval = user.getname() + "/" + user.getstate();
        return returnval;
    }
    return returnval;
}
int UserService::creategroup(uint32_t userid, string groupname, string groupdesc)
{

    Group group(-1, groupname, groupdesc);
    if (_groupmodel.createGroup(group))
    {
        uint32_t groupid = group.getgroupid();
        if (_groupmodel.addGroup(userid, "creator", groupid))
            return groupid;
    }
    return -1;
}
bool UserService::addgroup(uint32_t userid, int groupid, string role, Group& group)
{

    if (_groupmodel.addGroup(userid, role, groupid))
    {   
        group = _groupmodel.queryGroupdesc(groupid);
        return true;
    }
        

    return false;
}
void UserService::AddFriend(google::protobuf::RpcController *controller,
                            const ::user::AddFriendRequest *request,
                            ::user::AddFriendResponse *response,
                            ::google::protobuf::Closure *done)
{
    uint32_t userid = request->userid();
    uint32_t friendid = request->friendid();
    string val = addfriend(userid, friendid);

    if (val != "")
    {
        int idx = val.find(('/'));

        string name = val.substr(0, idx);
        string state = val.substr(idx + 1, val.size() - idx - 1);
        response->set_errcode(0);
        response->set_errmsg("");
        response->set_name(name);
        response->set_state(state);
    }
    else
    {
        response->set_errcode(1);
        response->set_errmsg("");
        response->set_name("");
        response->set_state("");
    }
    done->Run();
}

void UserService::CreateGroup(google::protobuf::RpcController *controller,
                              const ::user::CreateGroupRequest *request,
                              ::user::CreateGroupResponse *response,
                              ::google::protobuf::Closure *done)
{
    uint32_t userid = request->userid();
    string groupname = request->groupname();
    string groupdesc = request->groupdesc();
    int groupid;
    if ((groupid = creategroup(userid, groupname, groupdesc)) != -1)
    {
        response->set_errcode(0);
        response->set_groupid(groupid);
        response->set_groupname(groupname);
        response->set_groupdesc(groupdesc);
    }
    else
    {
        response->set_errcode(1);
        response->set_groupid(groupid);
        response->set_groupname(groupname);
        response->set_groupdesc(groupdesc);
    }
    done->Run();
}
void UserService::AddGroup(google::protobuf::RpcController *controller,
              const ::user::AddGroupRequest *request,
              ::user::AddGroupResponse *response,
              ::google::protobuf::Closure *done)
{
    uint32_t userid = request->id();
    int groupid = request->groupid();
    string role = request->role();
    Group group(groupid);
    if(addgroup(userid, groupid, role, group))
    {
        response->set_errcode(0);
        response->set_groupid(groupid);
        response->set_groupname(group.getgroupname());
        response->set_groupdesc(group.getgroupdesc());
    }
    else
    {
        response->set_errcode(1);
        response->set_groupid(-1);
        response->set_groupname("");
        response->set_groupdesc("");
    }
}
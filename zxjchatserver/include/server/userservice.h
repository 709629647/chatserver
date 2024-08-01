#include "chatservice.hpp"
#include "public.hpp"
#include <vector>
#include "muduo/base/Logging.h"
#include "chat.pb.h"
class UserService : public user::UserServiceRpc
{
public:
    string addfriend(uint32_t userid, uint32_t friendid);
    int creategroup(uint32_t userid, string groupname, string groupdesc);
    bool addgroup(uint32_t userid, int groupid, string role, Group& group);
    void AddFriend(google::protobuf::RpcController *controller,
                   const ::user::AddFriendRequest *request,
                   ::user::AddFriendResponse *response,
                   ::google::protobuf::Closure *done);
    void CreateGroup(google::protobuf::RpcController * controller,
                       const ::user::CreateGroupRequest* request,
                       ::user::CreateGroupResponse* response,
                       ::google::protobuf::Closure* done);
   void AddGroup(google::protobuf::RpcController * controller,
                       const ::user::AddGroupRequest* request,
                       ::user::AddGroupResponse* response,
                       ::google::protobuf::Closure* done);

private:
    UserModel _usermodel;
    OfflineMessageModel _offlinemessagemodel;
    FriendModel _friendmodel;
    GroupModel _groupmodel;
};
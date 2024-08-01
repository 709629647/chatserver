#ifndef FRIENDMODEL_HPP
#define FRIENDMODEL_HPP
#include <vector>
#include "user.hpp"
class FriendModel{
public:
    bool insert(int userid, int friendid);
    vector<User> query(int id);
private:

};
#endif
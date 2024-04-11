#ifndef GROUPMODEL_HPP
#define GROUPMODEL_HPP
#include "group.hpp"
class GroupModel{
public:
    bool createGroup(Group& group);
    bool addGroup(int id, string role, int groupid);
    vector<Group> queryGroup(int id);
    vector<int> queryGroupUser(int userid, int groupid);
    Group queryGroupdesc(int groupid);
private:

};
#endif
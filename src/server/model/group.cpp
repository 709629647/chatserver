#include "group.hpp"

int Group::getgroupid()
{
    return this->groupid;
}
string Group::getgroupname()
{
    return this->groupname;
}
string Group::getgroupdesc()
{
    return this->groupdesc;
}
vector<GroupUser>& Group::getgroupuser()
{
    return this->user;
}

void Group::setgroupid(int id)
{
    this->groupid = id;
}
void Group::setgroupname(string name)
{
    this->groupname = name;
}
void Group::setgroupdesc(string desc)
{
    this->groupdesc = desc;
}
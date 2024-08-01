#ifndef GROUP_HPP
#define GROUP_HPP
#include <string>
#include "groupuser.hpp"
#include <vector>
class Group
{
private:
    int groupid;
    string groupname;
    string groupdesc;
    vector<GroupUser> user;

public:
    Group(int groupid = -1, string name = "", string desc = "")
        : groupid(groupid), groupname(name), groupdesc(desc)
    {
    }
    int getgroupid();
    string getgroupname();
    string getgroupdesc();
    vector<GroupUser>& getgroupuser();

    void setgroupid(int id);
    void setgroupname(string name);
    void setgroupdesc(string desc);
    // vector<GroupUser> setgroupuser();
};

#endif
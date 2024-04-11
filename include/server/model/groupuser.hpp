#ifndef GROUPUSER_HPP
#define GROUPUSER_HPP
#include "user.hpp"
#include <string>
class GroupUser : public User
{
private:
    string role;

public:
    GroupUser(int id = -1, string name = "", string pwd = "", string state = "offline", string role = "normal")
        : User(id, name, pwd, state), role(role)
    {
    }
    string getrole();
    void setrole(string role);
};

#endif
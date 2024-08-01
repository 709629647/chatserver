#include "user.hpp"
void User::setid(int id)
{
    this->id = id;
}
void User::setname(string name)
{
    this->name = name;
}
void User::setpassword(string pwd)
{
    this->password = pwd;
}
void User::setstate(string state)
{
    this->state = state;
}
int User::getid()
{
    return id;
}
string User::getname()
{
    return name;
}
string User::getpassword()
{
    return password;
}
string User::getstate(){
    return state;
}
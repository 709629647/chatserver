#ifndef USER_HPP
#define USER_HPP
#include <string>
using namespace std;
class User
{
public:

    User(int id =-1, string name = "", string pwd = "", string state = "offline") : id(id), name(name), password(pwd), state(state)
    {
    }
    void setid(int id);
    void setname(string name);
    void setpassword(string pwd);
    void setstate(string state);
    int getid();
    string getname();
    string getpassword();
    string getstate();
private:
    int id;
    string name;
    string password;
    string state;
};
#endif
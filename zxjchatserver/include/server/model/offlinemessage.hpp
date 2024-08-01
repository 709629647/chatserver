#ifndef OFFLINEMESSAGE_HPP
#define OFFLINEMESSAGE_HPP
#include <string>
using namespace std;
class OfflineMessage
{
public:
     OfflineMessage(int id = -1, string message = "") : userid(id), message(message)
    {
    }
    void setuserid(int id);
    void setmessage(string name);
    
    int getuserid();
    string getmessage();
    
private:
    int userid;
    string message;
};
#endif
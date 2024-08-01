#include "offlinemessage.hpp"
void OfflineMessage::setuserid(int id)
{
    this->userid = id;
}
void OfflineMessage::setmessage(string message)
{
    this->message = message;
}

int OfflineMessage::getuserid()
{
    return userid;
}
string OfflineMessage::getmessage()
{
    return message;
}

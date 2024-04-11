#ifndef OFFLINEMESSAGEMODEL_HPP
#define OFFLINEMESSAGEMODEL_HPP
#include <vector>
#include "offlinemessage.hpp"
class OfflineMessageModel{
public:
    bool insert(OfflineMessage& message);
    vector<string> query(int id);
    bool remove(int id);
private:

};
#endif
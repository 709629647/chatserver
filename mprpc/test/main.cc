#include "test.pb.h"
#include <iostream>
using namespace fixbug;
int main()
{
    fixbug::LoginRequest login;
    login.set_name("zhangsan");
    login.set_pwd("123456");
    std::string send_str;
    if(login.SerializeToString(&send_str))
        std::cout<<send_str<< std::endl;
    LoginRequest  req;
    req.ParseFromString(send_str);  
    std::cout << req.name() <<" " <<req.pwd()<<std::endl;  
    return 0;
    // login.set
}
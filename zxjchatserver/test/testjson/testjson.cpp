#include "json.hpp"
using json = nlohmann::json;
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "lisi";
    js["msg"] = "ni hao woshi ";
    cout << js <<endl;
    }
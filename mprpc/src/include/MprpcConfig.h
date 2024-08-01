#pragma once
#include <unordered_map>
#include <iostream>

class MprpcConfig
{
public:
    void LoadConfig(const char* name);
    std::string GetConfigValue(const std::string& key);
private:
    std::unordered_map<std::string, std::string> m;

};
#pragma once
#include "MprpcConfig.h"
#include "MprpcChannel.h"
#include "MprpcController.h"
#include "MprpcProvider.h"
class MprpcApplication
{
public:
    static void init(int argc, char** argv);
    static MprpcApplication& getinstance();
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication& operator=(const MprpcApplication&) = delete;
    MprpcConfig& getConfig();

private:
    MprpcApplication(){};
    static MprpcConfig config_;
};
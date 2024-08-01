#include "MprpcApplication.h"
#include <iostream>
#include <unistd.h>
MprpcConfig MprpcApplication::config_;
void ArgErr()
{
    std::cout << "comand like -i config" << std::endl;
}
MprpcConfig& MprpcApplication::getConfig()
{
    return config_;
}
void MprpcApplication::init(int argc, char** argv)
{
    if(argc < 3)
    {
        ArgErr();
        exit(EXIT_FAILURE);
    }
    int c;
    std::string conf;
    while((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            conf = optarg;
            break;
        case '?':
            ArgErr();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    config_.LoadConfig(conf.c_str());
}
MprpcApplication& MprpcApplication::getinstance()
{
    static MprpcApplication app;
    return app;
}
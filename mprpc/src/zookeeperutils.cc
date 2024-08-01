#include "zookeeperutils.h"
#include "MprpcApplication.h"
void watcher_func(zhandle_t *zh, int type, 
        int state, const char *path,void *watcherCtx)
{
    if(type == ZOO_SESSION_EVENT)
    {
        if(state == ZOO_CONNECTED_STATE)
        {
            sem_t* sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}
ZKClient::ZKClient():m_zhandler_(NULL)
{
}
ZKClient::~ZKClient()
{
    if(m_zhandler_)
    {
        zookeeper_close(m_zhandler_);
    }
}
void ZKClient::Start()
{
    MprpcConfig& config =  MprpcApplication::getinstance().getConfig();
    std::string ip =  config.GetConfigValue("zookeeperip");
    std::string port = config.GetConfigValue("zookeeperport");
    std::string connstr = ip  + ":" + port; 
    m_zhandler_ = zookeeper_init(connstr.c_str(), &watcher_func, 30000, nullptr, nullptr, 0);
    if(m_zhandler_ == nullptr)
    {
        std::cout << "zookeeper init eeerr" <<std::endl;
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    
    zoo_set_context(m_zhandler_, &sem);
    sem_wait(&sem);
    std::cout << "init success"<< std::endl;
}
void ZKClient::Create(const char *path, const char *data, int datalen, int state)
{
    char pathbuf[128];
    int buflen = sizeof(pathbuf);
    int flag = zoo_exists(m_zhandler_, path, 0, nullptr);
    if(flag == ZNONODE)
    {   //state juedui shibushi yongjiuxing jiedian 
        flag = zoo_create(m_zhandler_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE, state, pathbuf, buflen);
        if(flag == ZOK)
        {
            std::cout << "create success:" << path << std::endl;
        }
        else
        {
            std::cout << "create failed:" << path << std::endl;
            exit(EXIT_FAILURE);
        }
    }

}
std::string ZKClient::GetData(const char *path)
{
    char buf[128] = {0};
    int buflen = sizeof(buf);
    int flag = zoo_get(m_zhandler_, path, 0, buf, &buflen, nullptr);
    if(flag == ZOK)
    {
        
        return buf;
    }
        std::cout << "getdata failed on" << path << std::endl;
        return "";
}
// int main(int argc, char** argv)
// {
//     MprpcApplication::init(argc, argv);
//     ZKClient zk;
//     zk.Start();
//     zk.Create("/hello", "nihao", 5, 0);
//     std::cout << zk.GetData("/nihao");
// }
#include "logger.h"
#include <time.h>
#include <iostream>
Logger& Logger::getInstance()
{
    static Logger log;
    return log;
}
Logger::Logger()
{
    std::thread writelog([&]()
    {
        for(;;)
        {
            time_t now = time(nullptr);
            tm* now_tm = localtime(&now);
            char file_name[128];
            snprintf(file_name, 128, "%d-%d-%dlog.txt", now_tm->tm_year + 1900, 
                    now_tm->tm_mon +1, now_tm->tm_mday);
            std::cout << file_name << std::endl;
            FILE* file = fopen(file_name, "a+");
            if(file == NULL)
            {
                std::cerr << ("open file err") << std::endl;
            }
            
            char data[128];
            snprintf(data, 128, "%2d-%2d-%2d [%s] =>: ", now_tm->tm_hour, 
                    now_tm->tm_min, now_tm->tm_sec, level_ == INFO ? "INFO" : "ERROR");
            std::string s = msg_queue_.Pop();
            s.insert(0, data);
            s.append("\n");
            fputs(s.c_str(), file);
            fclose(file);
        }
    });
    writelog.detach();
}
void Logger::setLogLevel(LogLevel level)
{
    level_ = level;
}
void Logger::Log(std::string msg)
{
    msg_queue_.Push(msg);
}
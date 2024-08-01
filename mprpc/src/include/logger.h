#pragma once
#include "lockqueue.h"
#include <thread>
#include   <unordered_map>
enum LogLevel{
    INFO,
    ERROR,
};
class Logger
{
private:
    lockqueue<std::string> msg_queue_;
    LogLevel level_;
    Logger();
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;
public:
    static Logger& getInstance();
    void setLogLevel(LogLevel level);
    void Log(std::string msg);
};

#define LOGINFO(formatstr, ...)  \
do  \
{   \
    Logger& log = Logger::getInstance();   \
    log.setLogLevel(LogLevel::INFO); \
    char  c[1024] = {0}; \
    snprintf(c, 1024, formatstr, ##__VA_ARGS__); \
    log.Log(c); \
} while (0);

#define LOGERROR(formatstr, ...)  \
do  \
{   \
    Logger& log = Logger::getInstance();   \
    log.setLogLevel(LogLevel::ERROR); \
    char  c[1024] = {0}; \
    snprintf(c, 1024, formatstr, ##__VA_ARGS__); \
    log.Log(c); \
} while (0);




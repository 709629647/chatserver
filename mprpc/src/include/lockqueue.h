#pragma once
#include <queue>
#include <mutex>
#include <string>
#include <condition_variable>
template <typename T>
class lockqueue
{
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cond_variable_;

public:
    void Push(T & msg)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(msg);
        cond_variable_.notify_all();
    }
    T Pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty())
        {
            cond_variable_.wait(lock);
        }
        T msg = queue_.front();
        queue_.pop();
        return msg;
    }
};

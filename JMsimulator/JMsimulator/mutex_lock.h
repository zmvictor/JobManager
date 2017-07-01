#pragma once

#include <mutex>

class MutexLock
{
public:
    explicit MutexLock(std::mutex* mutex_ptr) : mutex_ptr_(mutex_ptr) 
    {
        mutex_ptr_->lock();
    }

    ~MutexLock()
    {
        mutex_ptr_->unlock();
    }
private:
    // now owned
    std::mutex* mutex_ptr_;
};
//
// Created by rigry on 07.12.2024.
//

#ifndef PROJECTSYS_THREADSAFEQUEUE_H
#define PROJECTSYS_THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename  T>

class ThreadSafeQueue {
public:
    void push(T& value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
        condition_.notify_one();
    }

    bool pop(T& value)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this]() {return !queue_.empty(); });
        if(queue_.empty()) return false;
        value = queue_.front();
        queue_.pop();
        return true;
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }


private:
    mutable std::mutex mutex_;
    std::queue<T> queue_;
    std::condition_variable condition_;


};


#endif //PROJECTSYS_THREADSAFEQUEUE_H

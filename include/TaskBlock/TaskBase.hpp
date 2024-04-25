//
// Created by ziyu on 24-4-24.
//

#ifndef TASKBLOCK_TASKBASE_HPP
#define TASKBLOCK_TASKBASE_HPP

#define TASK_LOCK_RUN(X) lock(); X; unlock();

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//#define DEBUG // <---------------------------
#ifndef RELEASE
#include <assert.h>
#define ASSERT(f) assert(f)
#else
#define ASSERT(f) ((void)0)
#endif
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <mutex>

namespace zy
{
    class TaskBase
    {
    private:
        std::mutex mutexLock_;

    public:
        void lock() { mutexLock_.lock(); };
        void unlock() { mutexLock_.unlock(); };
        virtual bool task() = 0;
    };

}


#endif //TASKBLOCK_TASKBASE_HPP

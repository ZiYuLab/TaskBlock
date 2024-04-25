//
// Created by ziyu on 24-4-24.
//

#ifndef TASKBLOCK_TASKBLOCK_HPP
#define TASKBLOCK_TASKBLOCK_HPP

#include <thread>
#include <cstdio>
#include <mutex>
#include "TaskBase.hpp"

namespace zy
{
    class TaskBlock
    {
    private:
        bool threadStatus_ = false;
        bool threadRun_ = true;
        std::mutex lock_;
        std::thread *taskThreadPtr_ = nullptr;
        TaskBase *task_ = nullptr;

        static void modelTask(TaskBase *taskPtr, TaskBlock *controlPtr);

    public:
        TaskBlock(TaskBase &task);
        ~TaskBlock();

        bool genTaskTread(TaskBase &task);
        bool genTaskTread();
        bool stopTaskTread();
    };
}


#endif //TASKBLOCK_TASKBLOCK_HPP

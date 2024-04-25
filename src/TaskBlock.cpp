//
// Created by ziyu on 24-4-24.
//

#include "TaskBlock.hpp"

zy::TaskBlock::TaskBlock(zy::TaskBase &task)
    :task_(&task)
{

}

zy::TaskBlock::~TaskBlock()
{
    stopTaskTread();
    delete taskThreadPtr_;
}

void zy::TaskBlock::modelTask(zy::TaskBase *taskPtr, zy::TaskBlock *controlPtr)
{
    while (controlPtr->threadRun_)
    {
        taskPtr->task();
    }
    controlPtr->threadRun_ = false;
    controlPtr->threadStatus_ = false;
}

bool zy::TaskBlock::genTaskTread()
{
    ASSERT(task_);
    threadStatus_ = true;
    threadRun_ = true;
    taskThreadPtr_ = new std::thread(modelTask, task_, this);
    return true;
}

bool zy::TaskBlock::genTaskTread(zy::TaskBase &task)
{
    task_ = &task;
    return genTaskTread();
//    return true;
}

bool zy::TaskBlock::stopTaskTread()
{
    lock_.lock();
    threadRun_ = false;
    lock_.unlock();
    if (taskThreadPtr_ != nullptr)
        taskThreadPtr_->join();
    return true;
}





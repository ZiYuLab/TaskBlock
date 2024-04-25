//
// Created by ziyu on 24-4-25.
//

#include "DemoTaskA.h"

bool DemoTaskA::task() {
    DataDemo_t tmp;
    tmp.iData = 100;
    tmp.fData = 1212.12;
    tmp.timePoint = std::chrono::high_resolution_clock::now();
    TASK_LOCK_RUN(buffer_ = tmp);
    return true;
}

bool DemoTaskA::getBuffer(DataDemo_t &buffer)
{
//    lock();
    TASK_LOCK_RUN(buffer = buffer_);

//    unlock();
    return false;
}

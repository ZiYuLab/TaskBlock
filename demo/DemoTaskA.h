//
// Created by ziyu on 24-4-25.
//

#ifndef TASKBLOCK_DEMOTASKA_H
#define TASKBLOCK_DEMOTASKA_H

#include "TaskBase.hpp"
#include <chrono>

struct DataDemo_t
{
    int iData = 10;
    float fData = 1.2;
    std::chrono::high_resolution_clock::time_point timePoint;
};

class DemoTaskA : public zy::TaskBase {
private:
    DataDemo_t buffer_;
public:
    bool task();
    bool getBuffer(DataDemo_t &buffer);
};

#endif //TASKBLOCK_DEMOTASKA_H

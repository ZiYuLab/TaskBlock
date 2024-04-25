//
// Created by ziyu on 24-4-25.
//

#ifndef TASKBLOCK_DEMOTASKB_H
#define TASKBLOCK_DEMOTASKB_H

#include "TaskBase.hpp"
#include "DemoTaskA.h"
//#include ""

class DemoTaskB : public zy::TaskBase{

private:
    DemoTaskA *demoTaskAPtr_;

public:
    void init(DemoTaskA *demoTaskA);
    bool task();
};


#endif //TASKBLOCK_DEMOTASKB_H

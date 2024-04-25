//
// Created by ziyu on 24-4-25.
//

#include "DemoTaskB.h"
#include <iostream>

bool DemoTaskB::task()
{
    DataDemo_t tmp;
    demoTaskAPtr_->getBuffer(tmp);
    std::cout << tmp.iData << std::endl;
    std::cout << tmp.fData << std::endl;
    auto millisec_since_epoch =
            std::chrono::duration_cast<std::chrono::milliseconds>(tmp.timePoint.time_since_epoch())
                    .count();
    std::cout << millisec_since_epoch << std::endl << std::endl;
}

void DemoTaskB::init(DemoTaskA *demoTaskA)
{
    demoTaskAPtr_ = demoTaskA;
}

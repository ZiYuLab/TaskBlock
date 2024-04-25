#include <iostream>
#include "TaskBlock.hpp"
#include "demo/DemoTaskA.h"
#include "demo/DemoTaskB.h"

int main() {
    DemoTaskA taskA;
    DemoTaskB taskB;
    taskB.init(&taskA);

    zy::TaskBlock ABlock(taskA);
    zy::TaskBlock BBlock(taskB);

    ABlock.genTaskTread();
    BBlock.genTaskTread();

    while (true);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

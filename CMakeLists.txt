cmake_minimum_required(VERSION 3.27)
project(TaskBlock)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/TaskBlock/)

add_executable(${PROJECT_NAME} main.cpp
        include/TaskBlock/TaskBlock.hpp
        src/TaskBlock.cpp
        include/TaskBlock/TaskBase.hpp
        demo/DemoTaskA.cpp
        demo/DemoTaskA.h
        demo/DemoTaskB.cpp
        demo/DemoTaskB.h)

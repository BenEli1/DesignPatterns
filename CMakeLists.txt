cmake_minimum_required(VERSION 3.20)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesignPatterns main.cpp prototype.h abstractFactory.h factory.h observer.h command.h somethingManger.h factory2.h builder.h adapter.h bridge.h)

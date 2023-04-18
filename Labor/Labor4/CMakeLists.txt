cmake_minimum_required(VERSION 3.25)
project(Labor4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor4 main.cpp Domain/Fruit.cpp Domain/Fruit.h Time/Date.cpp Time/Date.h Time/Day.cpp Time/Day.h Time/ExactDate.cpp Time/ExactDate.h Time/Time.h Tests/TestTime/TestTime.cpp Tests/TestTime/TestTime.h Tests/TestTime/TestDay.cpp Tests/TestTime/TestDay.h)

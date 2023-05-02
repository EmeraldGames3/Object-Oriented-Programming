cmake_minimum_required(VERSION 3.25)
project(Labor4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor4 Shop.cpp Domain/Fruit.cpp Domain/Fruit.h Time/Date/Date.cpp Time/Date/Date.h Time/Day/Day.cpp Time/Day/Day.h Time/ExactDate/ExactDate.cpp Time/ExactDate/ExactDate.h Time/Time.h Tests/TestTime/TestTime.cpp Tests/TestTime/TestTime.h Tests/TestTime/TestDay/TestDay.cpp Tests/TestTime/TestDay/TestDay.h Tests/TestTime/TestDate/TestDate.cpp Tests/TestTime/TestDate/TestDate.h Tests/TestTime/TestExactDate/TestExactDate.cpp Tests/TestTime/TestExactDate/TestExactDate.h Domain/Domain.h Tests/TestDomain/TestDomain.cpp Tests/TestDomain/TestDomain.h Tests/TestAll.cpp Tests/TestAll.h UI/UI.h UI/UserInterface.cpp UI/UserInterface.h Repository/Repository.h Repository/FruitRepository.cpp Repository/FruitRepository.h Controller/FruitController.cpp Controller/FruitController.h Controller/Controller.h Tests/TestRepository/TestRepository.cpp Tests/TestRepository/TestRepository.h Tests/TestController/TestController.cpp Tests/TestController/TestController.h)

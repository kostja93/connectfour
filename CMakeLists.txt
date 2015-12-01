cmake_minimum_required(VERSION 3.3)
project(ConnectFourClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES connect_four_types.h Logger.c Logger.h)

add_executable(ConnectFour ${SOURCE_FILES} Client/ConnectFour.c Client/network_controll.c Client/network_controll.h 4clib.h 4clib.c)

# Test Programms
add_executable(Test4CLib 4clibtest.c 4clib.h 4clib.c)
add_executable(TestCLib cblibtest.c cblib.h cblib.c)
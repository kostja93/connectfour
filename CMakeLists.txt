cmake_minimum_required(VERSION 3.3)
project(ConnectFourClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ConnectFourTypes.h)

add_executable(ConnectFour ${SOURCE_FILES} Client/ConnectFour.c)
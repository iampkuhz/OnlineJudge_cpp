cmake_minimum_required(VERSION 3.3)
project(OnlineJudge_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

        tmp.cpp)
add_executable(OnlineJudge_cpp ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.21)
project(hw5)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread" )
add_executable(hw5 Student.h Index.cpp Index.h HashFunction.cpp HashFunction.h HashTable.cpp HashTable.h LinkedList.h main.cpp)


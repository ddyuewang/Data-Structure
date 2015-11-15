cmake_minimum_required(VERSION 3.3)
project(HashTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("/usr/local/include")
set(SOURCE_FILES main.cpp Node.h LinkedList.h LinkedList.cpp)
#set(SOURCE_FILES main.cpp Node.h)
add_executable(HashTable ${SOURCE_FILES})
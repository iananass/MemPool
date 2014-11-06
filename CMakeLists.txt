cmake_minimum_required(VERSION 2.8)
SET(GOAL MemMgr.exe)
PROJECT(${GOAL})

SET(SOURCES main.cpp abc.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++0x")

ADD_EXECUTABLE(${GOAL} ${SOURCES})

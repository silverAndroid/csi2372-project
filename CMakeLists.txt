cmake_minimum_required(VERSION 3.6)
project(CSI2372_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp gemstones.cpp gemstones.h deck.cpp deck.h cardFactory.cpp cardFactory.h chain.cpp chain.h players.cpp players.h)
add_executable(CSI2372_Project ${SOURCE_FILES})
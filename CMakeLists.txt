cmake_minimum_required(VERSION 3.6)
project(csi2372_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cardFactory.cpp
        cardFactory.h
        chain.h
        deck.cpp
        deck.h
        gemstones.cpp
        gemstones.h
        main.cpp
        player.cpp
        player.h discard_pile.cpp discard_pile.h trade_area.cpp trade_area.h hand.cpp hand.h table.cpp table.h)

add_executable(csi2372_project ${SOURCE_FILES})
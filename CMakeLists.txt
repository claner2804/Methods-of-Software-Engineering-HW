cmake_minimum_required(VERSION 3.27)
project(HW4)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW4 character.cpp
        fighter.cpp
        hero.cpp
        item.cpp
        main.cpp
        npc.cpp
        sorcerer.cpp
        exceptions.h)

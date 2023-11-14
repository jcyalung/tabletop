cmake_minimum_required(VERSION 3.26)
project(TableTop)

set(CMAKE_CXX_STANDARD 17)

add_executable(TableTop main.cpp
        Card.cpp
        Card.h
        supplement.h
        Deck.cpp
        Deck.h
        Golf.cpp
        Golf.h)

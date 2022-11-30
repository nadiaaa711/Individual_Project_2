cmake_minimum_required(VERSION 3.23)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final_Project
        Airlines.cpp
        Airports.cpp
        FileRandW.cpp
        main.cpp
        Routes.cpp Airlines.h Airports.h Routes.h FileRandW.h Node.cpp Node.h FindRoute.cpp FindRoute.h)

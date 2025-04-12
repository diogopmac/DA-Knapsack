cmake_minimum_required(VERSION 3.29)
project(project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(project2 src/main.cpp
        src/menu.cpp
        data_structures/pallet.cpp
        data_structures/truck.cpp
        src/DataReader.cpp)

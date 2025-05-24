cmake_minimum_required(VERSION 3.29.6)
project(project2)

set(CMAKE_CXX_STANDARD 20)
#set(SOURCE CMAKE_SOURCE_DIR)

add_executable(project2
        src/main.cpp
        src/Menu.cpp
        data_structures/pallet.cpp
        data_structures/truck.cpp
        src/DataReader.cpp
        src/Algorithms.cpp
)

#target_include_directories(project2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
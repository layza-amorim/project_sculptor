cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project src/main.cpp src/Sculptor.cpp src/Sculptor.hpp src/Voxel.hpp)
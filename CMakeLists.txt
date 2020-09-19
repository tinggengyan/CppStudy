# announce minimum version needed
cmake_minimum_required(VERSION 3.12)

# custom project name
project(CppStudy)

# set cpp version 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)


add_subdirectory(looper)
add_subdirectory(static)
add_subdirectory(net)

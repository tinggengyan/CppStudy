# announce minimum version needed
cmake_minimum_required(VERSION 3.23)

# custom project name
project(Test-coverage-catch2)

include(FetchContent)

# set cpp version 
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(tests)
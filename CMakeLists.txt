# announce minimum version needed
cmake_minimum_required(VERSION 3.23)

# custom project name
project(CppStudy)

# set cpp version 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)


add_subdirectory(looper)
add_subdirectory(static)
add_subdirectory(net)
add_subdirectory(variables)
add_subdirectory(macro)
add_subdirectory(conventional)
add_subdirectory(enum)

add_subdirectory(thread/)
add_subdirectory(or/)
add_subdirectory(explictdemo/)
add_subdirectory(pointlikeclass/)
add_subdirectory(functionlikeclass/)
add_subdirectory(namespace/)
add_subdirectory(shared_ptr/)
add_subdirectory(string/)
add_subdirectory(http/)
add_subdirectory(symbol/)
add_subdirectory(circularqueue)
add_subdirectory(file)
add_subdirectory(smartpoint/)
add_subdirectory(general/)
add_subdirectory(default_delete/)
add_subdirectory(map_interface/)
add_subdirectory(tests/)
add_subdirectory(jsondemo/)
add_subdirectory(array_and_vector/)
add_subdirectory(memory_align/)
add_subdirectory(c_cpp_string_chararray/)
add_subdirectory(inherit/)
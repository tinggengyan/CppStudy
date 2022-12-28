add_library(testlib SHARED c_header.c)
add_executable(externc_demo main.cpp cpp_class.cpp)
target_link_libraries(externc_demo testlib)

file(GLOB_RECURSE cppFiles ./*.cpp)

add_library(lib SHARED ${cppFiles} ${cFiles})

target_include_directories(lib PUBLIC ./include)
target_include_directories(lib PUBLIC ../include)

target_compile_features(lib PUBLIC cxx_std_17)



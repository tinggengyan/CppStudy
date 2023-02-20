# Testing library
FetchContent_Declare(
        catch2Lib
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch2Lib)

file(GLOB_RECURSE cpp_files ../lib/*.cpp)



add_executable(test_app unit_test.cpp ${cpp_files})

target_compile_features(test_app PRIVATE cxx_std_17)

target_include_directories(test_app PUBLIC ../include)
target_include_directories(test_app PUBLIC ../lib/include)

target_link_libraries(test_app PRIVATE lib Catch2::Catch2)
add_test(NAME test_app COMMAND test_app) # Command can be a target

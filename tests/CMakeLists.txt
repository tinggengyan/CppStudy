Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.6 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include_directories(../third_party)

add_executable(tests_catch2 unit_test_catch2.cpp)
target_link_libraries(tests_catch2 PRIVATE Catch2::Catch2)

add_executable(tests_fakeit unit_test_fakeit.cpp)
target_link_libraries(tests_fakeit PRIVATE Catch2::Catch2)
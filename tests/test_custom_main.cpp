//
// Created by TinggengYan on 2023/2/24.
//
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

int main( int argc, char* argv[] ) {
    // your setup ...
    int result = Catch::Session().run( argc, argv );
    // your clean-up...
    return result;
}
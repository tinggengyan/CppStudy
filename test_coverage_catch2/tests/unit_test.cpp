//
// Created by TinggengYan on 2023/2/19.
//
#define CATCH_CONFIG_MAIN

#include "Manager.h"
#include <catch2/catch.hpp>

TEST_CASE("main", "main") {
    Manager manager;

    auto result1 = manager.getData(1);
    auto result2 = manager.getData(2);
    auto result3 = manager.getData(3);
    auto result4 = manager.getData(4);


    REQUIRE(result1 == 1);
}

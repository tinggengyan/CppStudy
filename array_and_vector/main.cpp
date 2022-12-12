//
// Created by TinggengYan on 2022/12/13.
//
#include <string>
#include <iostream>
#include <vector>

int main() {

    std::string array[] = {"1", "2", "3"};
    // 这种构造方式很有意思
    std::vector<std::string> ve = std::vector<std::string>(array, array + 3);

    for (const auto &item: ve) {
        std::cout << "" << item << std::endl;
    }

};

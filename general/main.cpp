//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>
#include "vector"
#include "functional"
#include "map"
#include "stdlib.h"

std::vector<int> get() {
    std::vector<int> inner;
    inner.push_back(1);
    std::cout << "inner point:" << &inner << std::endl;
    return inner;
}


int main(void) {

    std::vector<int> vector = get();
    std::cout << "outer point:" << &vector << std::endl;


    std::map<std::string, int> map;


    return 1;
}
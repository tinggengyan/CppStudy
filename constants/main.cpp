#include "iostream"

#include "Foo.h"

//
// Created by TinggengYan on 2023/3/1.
// https://abseil.io/tips/140
//


int main() {
    Foo foo;
    foo.foo();

    std::cout << "main empty address: " << &inlineEmpty << std::endl;
    std::cout << "main simpleEmpty address: " << &simpleEmpty << std::endl;

    return 0;
}
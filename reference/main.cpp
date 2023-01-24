//
// Created by TinggengYan on 2022/11/30.
//


#include <string>
#include <iostream>

void method1(std::string s) {
    std::cout << "method1 address:" << &s << std::endl;

}

void method2(std::string &s) {
    std::cout << "method2 address:" << &s << std::endl;
}

void method3(std::string &s) {
    s = "method3";
}

int main() {

    std::string string = "hello world";
    std::cout << "main address:" << &string << std::endl;

    method1(string);
    method2(string);

    method3(string);
    std::cout << "after method3 value is :" << string << std::endl;


    return 0;
}
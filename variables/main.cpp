//
// Created by Tinggeng Yan on 2021/6/16.
//

#include <iostream>


//枚举类型
enum Color {
    RED,
    BLACK
} abc;

typedef int AGE;

extern int customValue;


void init() {

    customValue = 10;
}


int main() {

    init();

    Color red = RED;

    std::cout << red << std::endl;

    AGE myAge = 18;
    std::cout << myAge << std::endl;


//    std::cout << customValue << std::endl;


    return 1;
}
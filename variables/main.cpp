//
// Created by Tinggeng Yan on 2021/6/16.
//

#include <iostream>
#include <climits>

//枚举类型
enum Color {
    RED,
    BLACK
} abc;

typedef int AGE;

// 声明
extern int customValue;

// 定义
int customValue = 9;

void init() {
    customValue = 10;
}

void types() {

    int16_t int16t = 1;
    uint16_t uint16t = 0;
    long long l2 = 0;
    long l1 = 0;


    std::cout << "int16t:" << int16t << std::endl;
    std::cout << "uint16t:" << uint16t << std::endl;

    std::cout << "USHRT_MAX:" << USHRT_MAX << std::endl;
    std::cout << "SHRT_MAX:" << SHRT_MAX << std::endl;

};


int main() {

    init();
//
//    Color red = RED;
//
//    std::cout << red << std::endl;
//
//    AGE myAge = 18;
//    std::cout << myAge << std::endl;


//    std::cout << customValue << std::endl;

    types();

    return 1;
}
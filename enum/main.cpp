//
// Created by Tinggeng Yan on 2021/6/16.
//

#include <iostream>


///////
// 1. 直接定义传统枚举是会报错的,因为是没有作用域限制的
// 如果想避开这个限制,可以在外围加一个namespace

//enum EnumA {
//    A, B
//};
//
//enum EnumB {
//    A, B
//};

////////




// --------------------------------------------//
// 2. 推荐使用cpp11中提出的新feature enum class

class Person {

public:
    // 整个类的常量
    typedef enum {
        BOY = 0,
        GIRL
    } SexType;


};


enum class ChinaColor {
    RED,
    YELLOW
};

enum class WestColor {
    RED,
    YELLOW
};

int main() {
    ChinaColor c1 = ChinaColor::RED;
    WestColor c2 = WestColor::RED;

    std::cout << static_cast<int>(c1) << std::endl;
    std::cout << static_cast<int>(c2) << std::endl;
    std::cout << static_cast<int>(Person::SexType::BOY) << std::endl;


    return 0;
}
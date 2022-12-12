//
// Created by TinggengYan on 2022/12/12.
//
#include <iostream>

class Trivial {

public:
    // delete 标记，让编译器不要生成默认的构造函数
    Trivial() = delete;

    Trivial(int a) {

    }
};

class Foo {

public:
    int age = 19;

    // 标记 使用默认编译器生成的构造函数
    Foo() = default;

    Foo(int a) {

    };


};


int main() {
    Foo foo2;
    std::cout << "end" << std::endl;
    return 0;
}

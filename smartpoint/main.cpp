//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>
#include "vector"

class Man {
    int age;

public:
    ~Man() {
        std::cout << "~Man()" << std::endl;
    }
};

class sp {

private:
    Man *man;

public:
    sp(Man *man) {
        std::cout << "sp(Man *man) " << std::endl;
        this->man = man;
    }

    ~sp() {
        if (man) {
            delete man;
        }
    }

};

void test() {
    Man *pMan = new Man();
    sp s = pMan; // 调用sp的构造函数

}



int main(void) {


    test();

    return 1;
}
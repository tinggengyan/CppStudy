//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>

namespace {
    int a = 1;
    namespace parent {
        int a = 2;
        namespace sub {
            int a = 3;
        }
    }

}

int main(void) {

    std::cout << "root a = " << ::a << std::endl;
    std::cout << "parent a = " << parent::a << std::endl;
    std::cout << "sub a = " << parent::sub::a << std::endl;


    return 1;
}
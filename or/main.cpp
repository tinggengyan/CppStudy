//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <string>
#include <typeinfo>
#include <iostream>

struct Man {
    std::string name = "man";
};

class Animal {

};


int main(void) {
    Man man;

    std::cout << "info,struct name : " << typeid(man).name() << std::endl;
    std::cout << "info,struct name : " << typeid(&man).name() << std::endl;

    if (typeid(man) == typeid(Man)) {
        std::cout << "这样可以判断类型" << std::endl;
    }


    Animal animal;

    std::cout << "info,struct name : " << typeid(animal).name() << std::endl;
    std::cout << "info,struct name : " << typeid(&animal).name() << std::endl;


    return 1;
}
//
// Created by Tinggeng Yan on 2021/6/16.
//

#include <iostream>

class Animal {

public:
    Animal() {
        std::cout << "Animal() is called " << this << std::endl;
    }

    Animal(const Animal &a) {
        std::cout << "Animal (const Animal &) is called this: " << this << " arg animal:" << &a << std::endl;
    }

    Animal &operator=(const Animal &) {
        std::cout << "Animal & operator=(const Animal &) is called" << std::endl;
        return *this;
    }

    ~Animal() {
        std::cout << "~Animal() is called this: " << this << std::endl;
    }

};

class Dog {

public:

    // 第一种： 使用初始化列表。推荐
    Dog(const Animal &animal) : __animal(animal) {
        std::cout << "Dog(const Animal &animal) is called this: " << this << " arg animal pointer " << &animal
                  << std::endl;
    }

    // 第二种：构造函数赋值来初始化对象。

//    Dog(const Animal &animal) {
//        __animal = animal;
//        std::cout << "Dog(const Animal &animal) is called" << std::endl;
//    }


    ~Dog() {
        std::cout << "~Dog() is called" << std::endl;
    }

private:
    Animal __animal;

};

int main() {
    Animal animal;
    std::cout << std::endl;

    Dog d(animal);
    std::cout << std::endl;

    return 0;
}
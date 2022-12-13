//
// Created by TinggengYan on 2022/11/30.
//
#include "iostream"

class Basic {
public:
    virtual void say() = 0;
};


class Special1 : public Basic {
public:
    void say() override {
        std::cout << "Special1 say" << std::endl;
    };

public:
    ~Special1() {
        std::cout << "~Special1" << std::endl;
    }

};


int main() {

    Basic *basic = new Special1();
    Basic *basic2 = new Special1();
    

    return 0;
}
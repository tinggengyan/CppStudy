//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>

struct Man {
    int age;
};

template<class T>
class shared_ptr {
private:
    T *px;
public:
    shared_ptr(T *p) : px(p) {
    }

    T &operator*() const {
        return *px;
    };

    T *operator->() {
        return px;
    }
};


int main(void) {
    Man man;
    man.age = 18;

    shared_ptr<Man> ptr(&man);

    std::cout << "age:" << ptr->age;

    return 1;
}
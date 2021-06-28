//
// Created by Tinggeng Yan on 2020/6/27.
//

#include <memory>
#include <iostream>
#include "Request.h"


std::shared_ptr<Request> methodA() {
    std::shared_ptr<Request> ptr = std::make_shared<Request>();
    ptr->name = "one";

    std::cout << "ptr: address:" << &ptr << std::endl;
    std::cout << "ptr: obj address:" << ptr << std::endl;


    std::shared_ptr<Request> ptr2 = ptr;

    std::cout << "ptr: use count:" << ptr.use_count() << std::endl;
    std::cout << "ptr2: use count:" << ptr2.use_count() << std::endl;


    return ptr;
}

int main() {

    const std::shared_ptr<Request> &ptr = methodA();

    std::cout << "return ptr: use count:" << ptr.use_count() << std::endl;
    std::cout << "return ptr: name:" << ptr->name << std::endl;
    std::cout << "return ptr: address:" << &ptr << std::endl;
    std::cout << "return ptr: obj address:" << ptr.get() << std::endl;

    return 0;
}
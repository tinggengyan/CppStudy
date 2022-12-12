//
// Created by Tinggeng Yan on 2020/6/27.
//

#include <memory>
#include <iostream>
#include "Request.h"
#include "Http1Request.h"


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

void diff_between_constructor_make() {
    Request *feo = new Request();
    // 参数是 泛型的 指针
    std::shared_ptr<Request> sharedPtrA(feo);
    std::shared_ptr<Request> sharedPtrA_1(feo);
    // 参数是 泛型的 实例
    std::shared_ptr<Request> sharedPtrB = std::make_shared<Request>((*feo));
    sharedPtrB->name = "customName";

    std::cout << std::endl;
    std::cout << "--- 原始对象值 --- " << std::endl;
    std::cout << "raw address: " << feo << std::endl;

    // 两个引用自身的值比较
    std::cout << std::endl;
    std::cout << "--- 两个引用自身的值比较 --- " << std::endl;
    std::cout << "sharedPtrA address: " << sharedPtrA << std::endl;
    std::cout << "sharedPtrB address: " << sharedPtrB << std::endl;

    // 两个引用返回值比较
    std::cout << std::endl;
    std::cout << "--- 两个引用返回值比较 --- " << std::endl;
    std::cout << "sharedPtrA get return address: " << sharedPtrA.get() << std::endl;
    std::cout << "sharedPtrB get return address: " << sharedPtrB.get() << std::endl;

    // 两个两个引用是否指向同一个对象？答案，不是
    std::cout << std::endl;
    std::cout << "--- 两个两个引用是否指向同一个对象？ --- " << std::endl;
    std::cout << "sharedPtrA name " << sharedPtrA->name << std::endl;
    std::cout << "sharedPtrB name " << sharedPtrB->name << std::endl;

    std::cout << std::endl;
    std::cout << "--- 两个引用的计数 --- " << std::endl;
    std::cout << "sharedPtrA use count: " << sharedPtrA.use_count() << std::endl;
    std::cout << "sharedPtrA_1 use count: " << sharedPtrA_1.use_count() << std::endl;
    std::cout << "sharedPtrB use count: " << sharedPtrB.use_count() << std::endl;
}


void passShared_ptrValue(const std::shared_ptr<Request> ptr) {
    std::cout << "passShared_ptrValue :" << ptr.use_count() << std::endl;
}

void passShared_ptrReference(const std::shared_ptr<Request> &ptr) {
    std::cout << "passShared_ptrReference : use count:" << ptr.use_count() << std::endl;
    passShared_ptrValue(ptr);
}


void polymorphism() {
    std::shared_ptr<Request> request = std::make_shared<Http1Request>();
    request->send();
}

int main() {

    const std::shared_ptr<Request> &ptr = methodA();

    std::cout << "return ptr: use count:" << ptr.use_count() << std::endl;
    std::cout << "return ptr: name:" << ptr->name << std::endl;
    std::cout << "return ptr: address:" << &ptr << std::endl;
    std::cout << "return ptr: obj address:" << ptr.get() << std::endl;

    passShared_ptrReference(ptr);
    polymorphism();

    return 0;
}
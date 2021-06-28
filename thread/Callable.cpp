//
// Created by Tinggeng Yan on 2019-11-07.
//

#include "Callable.h"

Callable::Callable() {
    std::cout << " constructor " << std::endl;

    static pthread_once_t once = PTHREAD_ONCE_INIT;

    pthread_once(&once, [] {
        setup();
    });
}

void Callable::setup() {
    std::cout << " setup " << std::endl;
};


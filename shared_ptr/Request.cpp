//
// Created by Tinggeng Yan on 2020/7/13.
//

#include "Request.h"
#include <iostream>

void Request::send() {
    std::cout << "basic Request send" << std::endl;
}

Request::Request() {
    std::cout << "basic Request constructor" << std::endl;
}

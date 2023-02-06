//
// Created by Tinggeng Yan on 2019-11-09.
//

#include "Callable.h"
#include <chrono>
#include <thread>


void call_once();

std::once_flag flag1;

void simple_do_once() {
    std::string s = "";

    std::call_once(flag1, [&s]() {
        std::cout << "Simple example: called once" << std::endl;
        s = "simple";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    });

    std::cout << s << std::endl;
}

int main() {
//    Callable callable1;
//    Callable callable2;


    unsigned i;

    unsigned n = 2;

    int j = 0;
    for (i = n - 1; i >= 0; --i, ++j) {
        std::cout << "i=" << i << std::endl;
        if (j > 2) {
            break;
        }
    }

    simple_do_once();

    return 0;
}
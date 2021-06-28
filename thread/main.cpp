//
// Created by Tinggeng Yan on 2019-11-09.
//

#include "Callable.h"


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


    return 0;
}
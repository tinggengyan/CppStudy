#include "SimpleObj.h"
#include "common.h"

extern bool flag;

int main() {
    flag = true;
    std::cout << "flag in begin of main is " << flag << std::endl;

    SimpleObj obj1;

    SimpleObj obj2;

    std::cout << obj1.get_num();

    std::cout << std::endl;

    std::cout << obj2.get_num();

    std::cout << std::endl;

    std::cout << "flag in end of main is " << flag << std::endl;

    return 1;
}
//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>

using namespace std;

struct Trivial1 {
    int i; // 4
    char c; //1,对齐
};

struct Trivial2 {
    int i1; // 4
    int i2; // 4
};


struct Trivial3 {
    int i1; // 4
    char array[2]; //2
    int i2; //4
};

struct Trivial4 {
    char c1; // 1
    char c2; //1
    char c3; //1
};
struct Trivial5 {
    char c1; // 1
};

int main() {
    
    std::cout << "Trivial1 size: " << sizeof(Trivial1) << std::endl;
    std::cout << "Trivial2 size: " << sizeof(Trivial2) << std::endl;
    std::cout << "Trivial3 size: " << sizeof(Trivial3) << std::endl;
    std::cout << "Trivial4 size: " << sizeof(Trivial4) << std::endl;
    std::cout << "Trivial5 size: " << sizeof(Trivial5) << std::endl;

    return 0;
}
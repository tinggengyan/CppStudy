//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1 = "steve ";

    std::cout << &s1 << std::endl;


    s1.append("yan");

    std::cout << &s1 << std::endl;

    std::cout << s1 << std::endl;


    unsigned long start = s1.find_first_of('z');
    std::cout << start << std::endl;


    unsigned long size = s1.size();

    std::cout << s1.substr(start, size - start) << std::endl;


    return 0;
}
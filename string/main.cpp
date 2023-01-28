//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>

using namespace std;

void compareString() {
    std::string s1 = "s1";
    std::string s2 = "s1";
    std::string s3 = "s3";

    std::cout << s1.compare(s2) << std::endl;
    std::cout << s1.compare(s3) << std::endl;
    std::cout << s1.compare("s1") << std::endl;

}

void basic() {

    string s1 = "steve ";

    std::cout << &s1 << std::endl;


    s1.append("yan");

    std::cout << &s1 << std::endl;

    std::cout << s1 << std::endl;


    unsigned long start = s1.find_first_of('z');
    std::cout << start << std::endl;


    unsigned long size = s1.size();

    std::cout << s1.substr(start, size - start) << std::endl;
}


int main() {
//    basic();

    compareString();


    return 0;
}
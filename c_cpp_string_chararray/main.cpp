//
// Created by TinggengYan on 2022/12/7.
//

#include <iostream>

int main() {

    // c style string
    char *str_c_pointer = "abcd";
    char *str_c_pointer_ = "abcd\0abcd";

    char str_c_array[] = "abcd";
    char str_c_array_[] = "abcd\0abcd";

    std::cout << "str_c_pointer:" << str_c_pointer << std::endl;
    std::cout << "str_c_pointer size:" << sizeof(str_c_pointer) << std::endl;
    std::cout << "str_c_pointer str length:" << strlen(str_c_pointer)  << std::endl;

    std::cout << "str_c_pointer_:" << str_c_pointer_ << std::endl;
    std::cout << "str_c_pointer_ size:" << sizeof(str_c_pointer_) << std::endl;
    std::cout << "str_c_pointer_ str length:" << strlen(str_c_pointer_)  << std::endl;

    std::cout << "str_c_array:" << str_c_array << std::endl;
    std::cout << "str_c_array size:" << sizeof(str_c_array) << std::endl;
    std::cout << "str_c_array str length:" << strlen(str_c_array)  << std::endl;

    std::cout << "str_c_array_:" << str_c_array_ << std::endl;
    std::cout << "str_c_array_ size:" << sizeof(str_c_array_) << std::endl;
    std::cout << "str_c_array_ str length:" << strlen(str_c_array_)  << std::endl;

}
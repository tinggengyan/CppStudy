//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>

template<class T>
struct identity {
    // 定义方法,参数为第二个圆括号
    const T &operator()(const T &x) const {
        return x;
    };
};


int main(void) {
    identity<int> identity;
    const int &i = identity(45);
    std::cout << "value:" << i;

    return 1;
}
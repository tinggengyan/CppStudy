//
// Created by Tinggeng Yan on 2020/5/21.
//
#include <iostream>

struct Number {

};

class Fraction {

public:
    // 存在 explicit 就是错误的.
//    explicit
    Fraction(int num, int den = 2) : mNum(num), mDen(den) {}

    Fraction operator+(const Fraction &ref) {
        return Fraction(ref.mNum);
    }


    // 重载数组操作符
    Number operator[](int index) {
    };


    int mNum;
private:
    int mDen;

};


int main(void) {
    Fraction fraction(2, 2);
    Fraction a = fraction + 4; // 将 4 转换成了 Fraction 对象

    std::cout << a.mNum;

    return 1;
}
//
// Created by TinggengYan on 2022/12/17.
//

#ifndef CPPSTUDY_STARTTHREADMETHODS_H
#define CPPSTUDY_STARTTHREADMETHODS_H
#include <string>
#include <iostream>
#include <thread>

using namespace std;

void calculate(int start, int end, string flag) {
    std::cout << flag << "start " << endl;

    int sum = start;
    for (int i = start; i < end; ++i) {
        sum += i;
    }

    std::cout << "sum : " << sum << endl;
}

// --- begin ---- 方式一,将运行体和参数放在构造函数里传递进去
void method1() {
    thread t1(calculate, 1, 10000, "t1");
    thread t2(calculate, 1, 10, "t2");
    // 等待 t1 和 t2 结束，主线程再继续运行
    t2.join();
    t1.join();

    // 或者用 detach 操作，脱离主线程
//    t2.detach();
//    t1.detach();
}
// --- end ---- 方式一


// --- begin ---- 方式二, 用结构体包装运行体，和函数差不多
struct Run {
    void operator()(int start, int end, string flag) {
        std::cout << flag << "start " << endl;

        int sum = start;
        for (int i = start; i < end; ++i) {
            sum += i;
        }

        std::cout << "sum : " << sum << endl;
    }
};

void method2() {
    Run run;
    thread t1(run, 1, 10000, "t1");
    t1.join();
}

// --- end ---- 方式二


// --- begin ---- 方式三, 利用 lamda
void method3() {
    auto f = [](int start, int end, string flag) {
        std::cout << flag << " start " << endl;

        int sum = start;
        for (int i = start; i < end; ++i) {
            sum += i;
        }

        std::cout << "sum : " << sum << endl;
    };

    thread t1(f, 1, 10000, "t1");
    t1.join();
}
#endif //CPPSTUDY_STARTTHREADMETHODS_H

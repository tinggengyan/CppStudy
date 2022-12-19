//
// Created by TinggengYan on 2022/12/17.
//

#ifndef CPPSTUDY_FUTUREMETHODS_H
#define CPPSTUDY_FUTUREMETHODS_H

#include <iostream>

#include <string>
#include <vector>
#include <future>
#include <thread>

using namespace std;

long calculate2(int start, int end) {
    int sum = start;
    for (int i = start; i < end; ++i) {
        sum += i;
    }
    return sum;
}

void methodFuture() {

    vector<future<long>> task;
    int thread_num = thread::hardware_concurrency();
    long n = 10000000000;

    int div = n / thread_num;
    for (int i = 0; i < thread_num; ++i) {
        if (i != thread_num - 1) {
            task.push_back(async(calculate2, div * i + 1, div * (i + 1)));
        } else {
            task.push_back(async(calculate2, div * i + 1, n));
        }
    }

    long re = 0;
    for (auto &item: task) {
        re += item.get();
    }

    std::cout << re;

}


#endif //CPPSTUDY_FUTUREMETHODS_H

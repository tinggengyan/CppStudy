//
// Created by TinggengYan on 2022/12/17.
//

#ifndef CPPSTUDY_MUTEXMETHODS_H
#define CPPSTUDY_MUTEXMETHODS_H


#include <thread>
#include <mutex>
#include <iostream>

#include <string>
#include <vector>
#include <future>
#include <thread>

void sum_here(long param, long &result) {
    static std::mutex locker;
    std::lock_guard<std::mutex> lk(locker);// RAII
    result += param;
}

void calculate3(long start, long end, long &result) {
    long ret = 0;
    for (long i = start; i < end; ++i) {
        sum_here(i, result);
    }
}

void mutexMethod() {
    vector<thread> task;
    long thread_num = 10;
    long n = 10000, result = 0;
    long div = n / thread_num;

    for (long i = 0; i < thread_num; ++i) {
        if (i != thread_num - 1) {
            task.emplace_back(thread(calculate3, div * i + 1, div * (i + 1), ref(result)));
        } else {
            task.emplace_back(thread(calculate3, div * i + 1, n, ref(result)));
        }
    }

    for (auto &item: task) {
        item.join();
    }

    std::cout << result;

}


#endif //CPPSTUDY_MUTEXMETHODS_H

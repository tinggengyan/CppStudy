//
// Created by TinggengYan on 2022/12/17.
//

#ifndef CPPSTUDY_CONDITIONVARIABLEMETHODS_H
#define CPPSTUDY_CONDITIONVARIABLEMETHODS_H

#include <thread>
#include <iostream>
#include <vector>

std::mutex m;
std::condition_variable cv;

int globalStep = 0;

void work(int step) {
    std::cout << "step : " << step << " enter" << std::endl;

    // do work,mock many works
    std::this_thread::sleep_for(std::chrono::seconds(step));

    std::unique_lock<std::mutex> lock(m);

    cv.wait(lock, [&] {
        return step == globalStep;
    });
    std::cout << "step : " << step << " working" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    globalStep++;
    lock.unlock();
    cv.notify_all();
}


void mockConditionVariable() {

    const int steps = 10;
    std::vector<std::thread> th;
    for (int i = 0; i < steps; ++i) {
        th.emplace_back(std::thread(work, i));
    }

    for (auto &item: th) {
        item.join();
    }

}


#endif //CPPSTUDY_CONDITIONVARIABLEMETHODS_H

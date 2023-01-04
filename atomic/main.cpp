#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> count = {0};

struct A {
    float x;
    int y;
    long long z;
};

int main() {

    std::atomic<A> atomicA;
    std::cout << std::boolalpha << atomicA.is_lock_free() << std::endl;
    std::thread t1([]() {
        count.fetch_add(1);
    });

    std::thread t2([]() {
        count++;        // 等价于 fetch_add
        count += 1;     // 等价于 fetch_add
    });

    t1.join();
    t2.join();

    std::cout << count << std::endl;

};

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

// 宽松模式
void releax();

// 释放/消费模型
void releaseConsume();

// 释放/获取模型
void releaseAcquire();

// 顺序一致模型
void order_seq();

int main() {

    order_seq();

    return 0;
}

void order_seq() {
    std::atomic<int> counter = {0};
    std::__1::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([&](){
            counter.fetch_add(1, std::memory_order_seq_cst);
        });
    }

    for (auto& t : vt) {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
}

void releaseAcquire() {
    std::vector<int> v;
    std::atomic<int> flag = {0};
    std::thread release([&]() {
        v.push_back(42);
        flag.store(1, std::memory_order_release);
    });
    std::thread acqrel([&]() {
        int expected = 1; // must before compare_exchange_strong
        while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel)) {
            expected = 1; // must after compare_exchange_strong
        }
        // flag has changed to 2
    });
    std::thread acquire([&]() {
        while (flag.load(std::memory_order_acquire) < 2);
        std::cout << v.at(0) << std::endl; // must be 42
    });
    release.join();
    acqrel.join();
    acquire.join();
}

void releaseConsume() {// 初始化为 nullptr 防止 consumer 线程从野指针进行读取
    std::atomic<int *> ptr(nullptr);
    int v;
    std::thread producer([&]() {
        int *p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });
    std::thread consumer([&]() {
        int *p;
        while (!(p = ptr.load(std::memory_order_consume)));

        std::cout << "p: " << *p << std::endl;
        std::cout << "v: " << v << std::endl;
    });
    producer.join();
    consumer.join();
}

void releax() {
    std::atomic<int> counter = {0};
    std::__1::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([&]() {
            counter.fetch_add(1, std::memory_order_relaxed);
        });
    }

    for (auto &t: vt) {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
}

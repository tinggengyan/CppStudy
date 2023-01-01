#include <iostream>
#include <vector>
#include <thread>
#include "SimpleReadWriteLock.h"
#include "ReadWriteLock.h"

volatile int var = 10; // 保持变量 var 对内存可见性，防止编译器过度优化
SimpleReadWriteLock rwLock; // 定义全局的读写锁变量

ReadWriteLock adRwLock; // 定义全局的读写锁变量


void simple();

void Write() {
    rwLock.writeLock();
    var += 10;
    std::cout << "write var : " << var << std::endl;
    rwLock.writeUnlock();
}

void Read() {
    rwLock.readLock();
    std::cout << "read var : " << var << std::endl;
    rwLock.readUnlock();
}
void adWrite() {
    adRwLock.writeLock();
    var += 10;
    std::cout << "write var : " << var << std::endl;
    adRwLock.writeUnlock();
}

void adRead() {
    adRwLock.readLock();
    std::cout << "read var : " << var << std::endl;
    adRwLock.readUnlock();
}

void simple() {
    std::vector<std::thread> writers;
    std::vector<std::thread> readers;
    for (int i = 0; i < 10; i++) {  // 10 个写线程
        writers.push_back(std::thread(Write));  // std::thread t 的写法报错
    }
    for (int i = 0; i < 100; i++) {   // 100 个读线程
        readers.push_back(std::thread(Read));
    }
    for (auto &t: writers) {   // 写线程启动
        t.join();
    }
    for (auto &t: readers) {   // 读线程启动
        t.join();
    }
    std::cin.get();
}

void advanced() {
    std::vector<std::thread> writers;
    std::vector<std::thread> readers;
    for (int i = 0; i < 10; i++) {  // 10 个写线程
        writers.push_back(std::thread(adWrite));  // std::thread t 的写法报错
    }
    for (int i = 0; i < 100; i++) {   // 100 个读线程
        readers.push_back(std::thread(adRead));
    }
    for (auto &t: writers) {   // 写线程启动
        t.join();
    }
    for (auto &t: readers) {   // 读线程启动
        t.join();
    }
    std::cin.get();
}


int main() {
//    simple();
    advanced();
    return 0;
}

//
// Created by tinggengyan on 23-1-2.
//

#ifndef CPPSTUDY_SIMPLEREADWRITELOCK_H
#define CPPSTUDY_SIMPLEREADWRITELOCK_H

#include <mutex>

class SimpleReadWriteLock {
private:
    std::mutex readMtx;
    std::mutex writeMtx;
    int readCnt; // 已加读锁个数
public:
    SimpleReadWriteLock() : readCnt(0) {}

    void readLock() {
        readMtx.lock();
        if (++readCnt == 1) {
            writeMtx.lock();  // 存在线程读操作时，写加锁（只加一次）
        }
        readMtx.unlock();
    }

    void readUnlock() {
        readMtx.lock();
        if (--readCnt == 0) { // 没有线程读操作时，释放写锁
            writeMtx.unlock();
        }
        readMtx.unlock();
    }

    void writeLock() {
        writeMtx.lock();
    }

    void writeUnlock() {
        writeMtx.unlock();
    }
};


#endif //CPPSTUDY_SIMPLEREADWRITELOCK_H

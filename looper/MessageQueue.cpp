//
// Created by yantinggeng on 2019-04-27.
//

#include <iostream>
#include "MessageQueue.h"

void MessageQueue::addMessage(Message *msg) {
    queueMutex.lock();
    // 初始化或者队列中无数据
    if (head == nullptr) {
        head = tail = msg;
    } else {
        tail->setNext(msg);
        tail = msg;
    }
    queueMutex.unlock();
}


MessageQueue::MessageQueue() {
    this->head = this->tail = nullptr;
}

Message *MessageQueue::next() {
    queueMutex.lock();
    if (head == nullptr) {
        // TODO no msg
        queueMutex.unlock();
        return nullptr;
    }

    Message *msg = head;
    head = head->getNext();
    queueMutex.unlock();
    return msg;
}

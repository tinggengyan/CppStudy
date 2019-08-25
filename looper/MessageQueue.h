//
// Created by yantinggeng on 2019-04-27.
//

#ifndef APM_MESSAGEQUEUE_H
#define APM_MESSAGEQUEUE_H


#include "Message.h"
#include <mutex>

class MessageQueue {

private:

    Message *head, *tail; // 维护的链表的头尾
    mutex queueMutex;

public:

    MessageQueue();

    void addMessage(Message *msg);

    Message *next();


};


#endif //APM_MESSAGEQUEUE_H

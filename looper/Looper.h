//
// Created by yantinggeng on 2019-04-26.
//

#ifndef APM_LOOPER_H
#define APM_LOOPER_H

#include <semaphore.h>
#include "Message.h"
#include "MessageQueue.h"
#include "thread"

class Looper {

private:

    sem_t haveMsg;

    bool stop = false;
    MessageQueue queue;

    void handle(Message *msg);


public:

    Looper();

    ~Looper();

    void loop();

    void post(Message *message);


};


#endif //APM_LOOPER_H

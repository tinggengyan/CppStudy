//
// Created by yantinggeng on 2019-04-26.
//

#include "Looper.h"
#include <iostream>
#include <semaphore.h>

void Looper::loop() {

  while (true) {

    if (stop) {
      return;
    }

    auto *msg = queue.next();
    if (msg != nullptr) {
      handle(msg);
      delete (msg);
    } else {
      sem_wait(&haveMsg);
    }
  }
}

void Looper::handle(Message *msg) {
  // 处理消息
  cout << "handle:  " << msg->getWhat() << endl;
}

Looper::Looper() {

  sem_init(&haveMsg, 1, 0);

  // 开启工作线程
  std::thread workT(&Looper::loop, this);
  workT.detach();
}

Looper::~Looper() { stop = true; }

void Looper::post(Message *message) {

  queue.addMessage(message);

  sem_post(&haveMsg);
}

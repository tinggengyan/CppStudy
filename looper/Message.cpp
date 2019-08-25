//
// Created by yantinggeng on 2019-04-26.
//

#include <iostream>
#include "Message.h"


Message::Message() {
    this->what = -1;
    this->next = nullptr;
}


void Message::setWhat(int what) {
    this->what = what;
}

int Message::getWhat() {
    return what;
}


void Message::setObj(string data) {
    this->obj = data;
}

string Message::getObj() {
    return this->obj;
}


void Message::setNext(Message *next) {
    this->next = next;
}

Message *Message::getNext() {
    return this->next;
}

Message::~Message() {

}



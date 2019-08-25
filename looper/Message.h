// Looper 处理消息
// Created by yantinggeng on 2019-04-26.
//

#ifndef APM_MESSAGE_H
#define APM_MESSAGE_H

#include "string"

using namespace std;


class Message {

private:

    int what; // 消息的类型

    string obj;// 待处理的数据

    Message *next; // 下一条消息

public:

    Message();

    virtual ~Message();

    void setWhat(int what);
    int getWhat();

    void setObj(string data);
    string getObj();

    void setNext(Message *next);
    Message* getNext();


};


#endif //APM_MESSAGE_H

//
// Created by Tinggeng Yan on 2019-11-09.
//

#include "sheader.h"

#include "stdio.h"
#include "iostream"


struct Header {

    int cid;
    int id;

};

int main() {
    Header header;
    header.id = 1;
    header.cid = 100;

    // 复制一份
    Header h = header;
    h.id = 2;


    std::cout << "header:" << &header;
    std::cout << ",header.id:" << header.id;

    std::cout << ",h:" << &h;
    std::cout << ",h.id:" << h.id;
    std::cout << ",h.cid:" << h.cid;


    return 0;
}
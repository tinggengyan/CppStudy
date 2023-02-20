//
// Created by TinggengYan on 2023/2/19.
//

#include "include/Manager.h"

int Manager::getData(int index) {
    switch (index) {
        case 1:
            std::cout<<"is 1"<<std::endl;
            break;
        case 2:
            std::cout<<"is 2"<<std::endl;
            break;
        default:
            std::cout<<"is default"<<std::endl;
            break;
    }
    return index;
}

Manager::Manager() {
    std::cout <<" constructor "<<std::endl;
}

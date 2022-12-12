//
// Created by Tinggeng Yan on 2020/7/13.
//

#ifndef CLIONPROJECT_REQUEST_H
#define CLIONPROJECT_REQUEST_H

#include <string>

class Request {

public:
    std::string name;

    virtual void send() = 0;
};


#endif //CLIONPROJECT_REQUEST_H

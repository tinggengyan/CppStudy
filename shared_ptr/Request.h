//
// Created by Tinggeng Yan on 2020/7/13.
//

#ifndef CLIONPROJECT_REQUEST_H
#define CLIONPROJECT_REQUEST_H

#include <string>

class Request {

public:
    std::string name;

    Request();

    virtual void send();
};


#endif //CLIONPROJECT_REQUEST_H

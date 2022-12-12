//
// Created by TinggengYan on 2022/12/12.
//

#ifndef CPPSTUDY_HTTP1REQUEST_H
#define CPPSTUDY_HTTP1REQUEST_H


#include "Request.h"

class Http1Request : public Request {
public:
    Http1Request();

    void send();
};


#endif //CPPSTUDY_HTTP1REQUEST_H

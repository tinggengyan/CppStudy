//
// Created by Tinggeng Yan on 2020/6/27.
//

#include <memory>
#include <iostream>
#include "Request.h"
#include "Http1Request.h"

#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, shared_ptr<Request>> map;

    auto request1 = std::make_shared<Http1Request>();
    request1->name = "request1";
    auto request2 = std::make_shared<Http1Request>();
    request2->name = "request2";

    map.insert({1, request1});
    map.insert({2, request2});


    for (auto &item: map) {
        std::cout << "key :" << item.first << ", value :" << item.second->name << std::endl;
    }


    return 0;
}
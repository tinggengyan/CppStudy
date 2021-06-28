//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>

#include "httplib.h"

using namespace std;

int main() {
    httplib::Client cli("www.taobao.com", 8080);
    auto res = cli.Get("/hi");

    std::cout << "status:" << res->status << std::endl;
    std::cout << "header size:" << res->headers.size() << std::endl;
    cout << res->get_header_value("Content-Type") << endl;

    return 0;
}
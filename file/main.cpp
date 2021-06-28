//
// Created by Tinggeng Yan on 2019-11-09.
//

#include <string>
#include <iostream>
#include <fstream>
#include<filesystem>

using namespace std;

int main() {

    ofstream outfile("./test.txt", ios::app);
    if (!outfile) {
        std::cout << "文件打开失败" << std::endl;
    } else {
        std::cout << "文件打开成功" << std::endl;
    }
    outfile
            << "firsttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt";
    outfile << std::endl;
    outfile << "one";
    outfile << std::endl;

//    cout << "当前程序执行路径:" << filesystem::current_path() << endl;


    ifstream infile("./test.txt");

    std::string value;
    if (infile) {
        while (infile >> value) {
            cout << value << std::endl;
        }
    } else {
        std::cout << "文件打开失败" << std::endl;
    }

//    char buffer[256];
//    while (!infile.eof()) {
//        infile.getline(buffer, 100);
//        cout << buffer << std::endl;
//    }


    return 0;
}
#include <iostream>

extern bool flag;

class SimpleObj {
public:
    SimpleObj();

    ~SimpleObj();

    int get_num();

private:
    int num;
};
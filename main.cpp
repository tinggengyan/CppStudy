#include <iostream>

using namespace std;

// define the function
int simpleDataType();

int main() {

    cout << "my name is steve,it is my test in cpp";

    simpleDataType();
    return 0;

}

// show the usage of  data type
int simpleDataType() {
    // basic data type
    int a = 1;
    char b = 'b';
    long c = 2;
    short d = 1;

    cout << "get the size by  data type :" << endl;
    cout << "the size of int is " << sizeof(int) << "" << endl;
    cout << "get the size by variable :" << endl;
    cout << "the size of variable a is " << sizeof a << "" << endl;

    return 0;
}
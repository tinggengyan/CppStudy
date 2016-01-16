#include <iostream>

using namespace std;

//define the function
int sqr(int);

int main() {
    //define a variable
    int a = 0;
    //input a int value from the console
    cout << "please input a value to a ";
    cin >> a;
    //output the string
    cout << "my name is steve,it is my test in cpp" << endl;
    cout << "what is get is " << a << endl;
    cout << "call the sqp method:" << sqr(5);
    return 0;
}

int sqr(int a) {
    return a * 6;
}
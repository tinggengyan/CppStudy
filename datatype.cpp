// show the usage of the data type
// Created by Steve on 2016/1/16.
//

#include <iostream>
#include <climits>

#define SURNAME "Yan";
const int AGE = 17;

using namespace std;

//function define
int simpleRadix();

void simpleDefination();


//the main function
int main() {
//    simpleDefination();
    simpleRadix();
    return 0;
}

void simpleDefination() {// basic int data type
    int a = 1;  //initialize a to 1
    char b = 'b';
    long c = 2 + a;
    short d = 1;

    cout << "get the size by  data type :" << endl;
    cout << "the size of int is " << sizeof(int) << " bytes " << endl;
    cout << "get the size by variable :" << endl;
    cout << "the size of variable a is " << sizeof a << " bytes " << endl;

    cout << "short is " << sizeof(short) << " bytes " << endl;
    cout << "long is " << sizeof(long) << " bytes " << endl;

    cout << "max int is " << INT_MAX << endl;
    cout << "max long is " << LONG_MAX << endl;
    cout << "max short is " << SHRT_MAX << endl;
    cout << "Minimum int value is " << INT_MIN << endl;
    cout << "Bits per byte is " << CHAR_BIT << endl;

    cout << SURNAME;
    cout << "'s AGE IS " << AGE;
}


//Radix
int simpleRadix() {
    int chest = 42; //decimal integer constant
    int waist = 0x42; //hexadecimal integer constant
    int inseam = 042; //octal integer constant
    cout << "chest=" << chest;
    cout << endl;
    cout << "waist=" << waist;
    cout << endl;
    cout << "inseam=" << inseam;
    cout << endl;
    return 0;
}





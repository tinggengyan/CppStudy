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

int simpleConvertion();

int simpleCompoundType();


//the main function
int main() {
//    simpleDefination();
//    simpleRadix();
    simpleCompoundType();
    return 0;
}

void simpleDefination() {// basic int data type
    int a = 1;  //initialize a to 1
    char b = 'b';
    long c = 2 + a;
    short d = 1;
    bool isReady = true;
    bool isOk = false;

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

    if (isReady) {

        cout << isOk;
    }


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

    int c = 90;
    cout << "basic 90:";
    cout << hex;  //remind the change the number base
    cout << c;
    cout << endl;


    // char is also a int type
    char ch = 77; //77==M
    int i = ch;
    cout << dec;
    cout << "char " << ch << " is also a int type: " << i;

    cout << "displaying the usage of cout.put()" << endl;
    // put a char to the out
    cout.put(ch);
    cout << endl;
    return 0;
}

//Auto convertion
int simpleConvertion() {
    char mChar = 'a';
    int mInt = 1;
    long mLong = 1000;
    float mFlout = 0.9f;
    double mDouble = 0.99f;
    return 0;
}


//simple compound types
int simpleCompoundType() {
    int ages[] = {10, 11, 12, 14};
    float scores[9];
    cout << "array size :" << sizeof(ages)<< "and"<<sizeof(scores);
    cout << endl;
    cout << "array item bytes:" << sizeof(ages[0]);
    cout << endl;
    return 0;
}

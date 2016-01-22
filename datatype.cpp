// show the usage of the data type
// Created by Steve on 2016/1/16.
//

#include <iostream>
#include <climits>
#include <cstring>

#define SURNAME "Yan";
const int AGE = 17;

using namespace std;

//function define
int simpleRadix();

void simpleDefination();

int simpleConversion();

int simpleCompoundType();

int getString();

int getStringByLine();

int getStringByGet();


//the main function
int main() {
//    simpleDefination();
//    simpleRadix();
//    simpleCompoundType();
//    simpleConversion();
//    getString();
//    getStringByLine();
    getStringByGet();
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

//Auto conversion
int simpleConversion() {
    char mChar = 'a';
    cout << "mChar:" << mChar << endl;
    //char is int
    int mInt = mChar + 1;
    cout << "mInt:" << mInt << endl;
    long mLong = 1000;
    long convertLong = mInt;
    cout << "mLong:" << mLong << endl;
    cout << "convertLong:" << convertLong << endl;
    float mFlout = 0.9e9;
    float convertFloat = mInt;
    cout << "mFlout:" << mFlout << endl;
    cout << "convertFloat:" << convertFloat << endl;
    double mDouble = 0.99f;
    double convertDouble = mInt;
    cout << "mDouble:" << mDouble << endl;
    cout << "convertDouble:" << convertDouble << endl;
    //zero is false,otherwise is true;
    bool hasMoney = false;
    bool hasHouse = 0;
    bool hasTalent = 100;
    cout << "hasMoney:" << hasMoney << "," << "hasHouse:" << hasHouse << "," << "hasTalent:" << hasTalent << endl;
    //two numbers can auto convert to the destination type
    float dividerFloat = 9 / 8.0;
    int dividerInt = 9 / 8.0;
    cout << "dividerFloat:" << dividerFloat << endl;
    cout << "dividerInt:" << dividerInt << endl;
    //  expression conversion
    short short1 = 256;
    short short2 = 255;
    short short3 = short1 + short2;
    cout << "short3:" << short3 << endl;
    return 0;
}


//simple compound types
int simpleCompoundType() {
    //simple array and give all init values
    int ages[] = {10, 11, 12, 14};
    //define the array by not init values
    float scores[9];
    //default number is zero
    float initByGivenDefault[9] = {};
    cout << "array obj : " << sizeof(ages) << " bytes and " << sizeof(scores) << " bytes";
    cout << endl;
    cout << "array item bytes: " << sizeof(ages[0]);
    cout << endl;
    cout << "array item not init: " << scores[5];
    cout << endl;
    cout << "array item by init : " << initByGivenDefault[5];
    cout << endl;
    cout << "does't exit item,will out the exception data: " << initByGivenDefault[9];
    cout << endl;
    cout << "array has items:" << sizeof(ages) / sizeof(ages[0]);
    cout << endl;

    /**
     * the following is String
     */
    // C style
    char dogs[5] = {'d', 'o', 'g', 's'}; //not a string
    char cats[5] = {'c', 'a', 't', 's', '\0'}; //is a string,the length includes the end sign
    char pigs[5] = {'p', 'i', 'g', '\0'};
    cout << "cat:" << cats << endl;
    cout << "dog:" << dogs << endl;

    //strlen return the string characters length ,not the array size
    cout << "cat length:" << strlen(cats);
    cout << endl;
    cout << "dog length:" << strlen(dogs);
    cout << endl;
    cout << "pig length:" << strlen(pigs);
    cout << endl;

    return 0;
}


//input string
int getString() {
    //simple input
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name: \n";
    cin >> name;
    cout << "Enter your favourite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    // when input words include blank will cause some problems
    // such the above first input 'steve yan',then will pass the dessert input
    // the word behind  blank ,yan will be for the dessert
    // because the sentence is recognize as finished by the blank ,tab ,and enter
    // so the word yan will in the input stream until the next used
    // so the word be for the dessert auto.

    return 0;
}


//input string,but not record the enter character
int getStringByLine() {
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name: \n";
    //can most input the 19 chars, the last one is end signal
    cin.getline(name, 20);
    cout << "Enter your favourite dessert:\n";
    cin.getline(dessert, 20);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}


// this way ,the Stream will record the enter signal
int getStringByGet(){
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name: \n";
    //can most input the 19 chars, the last one is end signal
    cin.get(name, 20);
    cin.get();
    cout << "Enter your favourite dessert:\n";
    // here will be input the enter signal
    cin.get(dessert, 20);
    cin.get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}
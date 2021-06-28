//
// Created by Tinggeng Yan on 2021/6/16.
//

#include <iostream>

// # 本质是将后续的内容进行字符串化
#define func1(s) std::cout<<s<<std::endl;

#define func2(s) std::cout<<#s<<std::endl;

#define exp2(s) #s

// ## 将前后字符进行拼接.组成一个变量名,要求变量名必须存在,前后的空格无所谓,不应该
#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在

#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在

#define gc_hello1 "I am gc_hello1"


// 续行操作符 \ ,用于在一行解决不了的时候,进行换行使用的;

#define MAX(a, b)  ((a)>(b))?(a) \
:(b);


int main() {

    func1("abc");

    func1(10);

    func2(abc);

    std::string s = exp2(abcdefghijk);
    std::cout << s << std::endl;

    const char *gc_hello = "I am gc_hello";

    expA(hello);
    expB(hello1);

    std::string b = "bb";
    std::string m = "mm";

    std::string max = MAX(b, m);
    std::cout << max << std::endl;

    return 1;
}
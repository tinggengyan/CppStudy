//
// Created by TinggengYan on 2023/3/1.
//

#include "Foo.h"

void Foo::foo() {

    std::cout << "foo empty address: " << &inlineEmpty << std::endl;
    std::cout << "foo simpleEmpty address: " << &simpleEmpty << std::endl;

}

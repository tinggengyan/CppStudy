// 2.x 版本必须加这个
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// 可以访问 private 成员
#include "test_enable_header.h"

#include <catch2/catch.hpp>
#include <fakeit.h>

using namespace fakeit;

struct SomeInterface {
    virtual int foo(int) = 0;

    virtual int bar(int, int) = 0;

    virtual int baz(int *, int &) = 0;
};

class ITrivialInterface {
public:
    virtual int foo1() = 0;
};


// 能 mock 的方法，必须是 virtual 的；
// limits from https://github.com/eranpeer/FakeIt
/**
 *
    Currently only GCC, Clang and MSC++ are supported.
    On GCC, optimization flag O2 and O3 are not supported. You must compile the test project with -O1 or -O0.
    In MSC++, your project must have Edit And Continue debug mode on (https://msdn.microsoft.com/en-us/library/esaeyddf.aspx) which is same of /ZI compiler switch. If you don't use this, you will have exceptions mocking destructors (which includes unique_ptr and other smart pointers).
    Can't mock classes with multiple inheritance.
    Can't mock classes with virtual inheritance.
    Currently mocks are not thread safe.
 */

class Foo {
public:
    virtual void foo1() {
    };

    virtual int foo2(int m) {
        return 2;
    };
};


TEST_CASE("simple_mock", "[mock_public]") {
    Mock<SomeInterface> mock;
    // Stub a method to return a value once
    When(Method(mock, foo)).Return(1);

    // Stub multiple return values (The next two lines do exactly the same)
    When(Method(mock, foo)).Return(1, 2, 3);
    When(Method(mock, foo)).Return(1).Return(2).Return(3);

    // Return the same value many times (56 in this example)
    When(Method(mock, foo)).Return(56_Times(1));

    // Return many values many times (First 100 calls will return 1, next 200 calls will return 2)
    When(Method(mock, foo)).Return(100_Times(1), 200_Times(2));

    // Always return a value (The next two lines do exactly the same)
    When(Method(mock, foo)).AlwaysReturn(1);
    Method(mock, foo) = 1;

    Mock<ITrivialInterface> trivialInterface;
    When(Method(trivialInterface, foo1)).Return(1);

};


TEST_CASE("simple_mock_Foo", "[Foo]") {
    Mock<Foo> mock;

    fakeit::When(Method(mock, foo2)).Return(1);

    std::cout << mock.get().foo2(1) << std::endl;

    fakeit::Verify(Method(mock, foo2));
    fakeit::Verify(Method(mock, foo2).Using(1));

}

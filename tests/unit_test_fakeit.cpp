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

}

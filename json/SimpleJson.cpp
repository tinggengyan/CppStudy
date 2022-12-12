// Serialize example
// This example shows writing JSON string with writer directly.

#include "rapidjson/prettywriter.h" // for stringify JSON
#include <utility>
#include <iostream>
#include "rapidjson/reader.h"

using namespace rapidjson;

class Person {
public:
    Person(std::string name, unsigned age) : name_(std::move(name)), age_(age) {}

    Person(const Person &rhs) : name_(rhs.name_), age_(rhs.age_) {}

    virtual ~Person();

    Person &operator=(const Person &rhs) {
        name_ = rhs.name_;
        age_ = rhs.age_;
        return *this;
    }

    template<typename Writer>
    void Serialize(Writer &writer) const {
        // This base class just write out name-value pairs, without wrapping within an object.
        writer.StartObject();
        writer.String("name");
#if RAPIDJSON_HAS_STDSTRING
        writer.String(name_);
#else
        writer.String(name_.c_str(), static_cast<SizeType>(name_.length())); // Supplying length of string is faster.
#endif
        writer.String("age");
        writer.Uint(age_);
        writer.EndObject();
    }

private:
    std::string name_;
    unsigned age_;
};

Person::~Person() {
}

int main(int, char *[]) {

    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    Person person("steve", 12);

    person.Serialize(writer);

    std::cout << "" << sb.GetString();

    return 0;
}
#include <unordered_map>
#include <iostream>

int main() {

    std::unordered_map<std::string, std::string> map;
    auto value1 = std::pair<std::string, std::string>("a", "name");
    auto r1 = map.insert(value1);

    auto value2 = std::pair<std::string, std::string>("a", "age");
    auto r2 = map.insert(value2);


    std::cout << r1.first->second << std::endl;
    std::cout << r2.first->second << std::endl;

    std::cout << "find value is " << map.find("a")->second << std::endl;



    std::cout << "find value is " << map.find("a")->second << std::endl;



    map["a"] = "after ";

    std::cout << "find value is " << map.find("a")->second << std::endl;


    return 0;
}
//
// Created by TinggengYan on 2022/12/5.
//

#include <iostream>
#include <vector>

template<typename T>
class FeatureValue {
private:
    T value;

public:

    FeatureValue() = default;

    T getValue();

    void setValue(T t);

};

template<typename T>
T FeatureValue<T>::getValue() {
    return FeatureValue::value;
}

template<typename T>
void FeatureValue<T>::setValue(T t) {
    FeatureValue::value = t;
}

template<typename T>
void putFeature(const std::string &category, const std::string &key, T value, int version) {
    FeatureValue<std::string> fv;
    fv.setValue(value);

    std::cout << "value: " << fv.getValue() << std::endl;
}

int main() {

    putFeature("cate", "ke", "value", 1);

    return 0;
}


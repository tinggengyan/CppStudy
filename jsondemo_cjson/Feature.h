//
// Created by TinggengYan on 2022/12/28.
//

#ifndef CPPSTUDY_FEATURE_H
#define CPPSTUDY_FEATURE_H

#include <string>

class Feature {
private:
    std::string category;
    std::string key;
    std::string values;
    std::string type;
    int version;

public:
    const std::string &getCategory() const {
        return category;
    }

    void setCategory(const std::string &category) {
        Feature::category = category;
    }

    const std::string &getKey() const {
        return key;
    }

    void setKey(const std::string &key) {
        Feature::key = key;
    }

    const std::string &getValues() const {
        return values;
    }

    void setValues(const std::string &values) {
        Feature::values = values;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        Feature::type = type;
    }

    int getVersion() const {
        return version;
    }

    void setVersion(int version) {
        Feature::version = version;
    }


};


#endif //CPPSTUDY_FEATURE_H

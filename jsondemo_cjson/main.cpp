#include <cjson/cJSON.h>
#include <iostream>
#include "Feature.h"


void DeserializeFromStr();

void SerializeToStr();

int main() {
    DeserializeFromStr();
    SerializeToStr();
    return 0;
}

void SerializeToStr() {
    Feature feature;
    feature.setVersion(1);
    feature.setType("int");
    feature.setValues("values");
    feature.setKey("key");
    feature.setCategory("libra");

    cJSON *feature_js_obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(feature_js_obj, "version", feature.getVersion());
    cJSON_AddStringToObject(feature_js_obj, "key", feature.getKey().c_str());
    cJSON_AddStringToObject(feature_js_obj, "values", feature.getValues().c_str());
    cJSON_AddStringToObject(feature_js_obj, "category", feature.getCategory().c_str());

    char *string_value = cJSON_PrintUnformatted(feature_js_obj);
    std::string json_string = std::string(string_value);
    cJSON_Delete(feature_js_obj);

    std::cout << "SerializeToStr" << std::endl;
    std::cout << json_string << std::endl;
}

void DeserializeFromStr() {
    const char *string = "{\"category\":\"libra\",\"key\":\"appid\",\"values\":\"1233\",\"type\":\"int\",\"version\":1}";
    cJSON *json = cJSON_Parse(string);
    Feature feature;

    char *category = cJSON_GetObjectItem(json, "category")->valuestring;
    feature.setCategory(std::string(category));

    char *key = cJSON_GetObjectItem(json, "key")->valuestring;
    feature.setKey(std::string(key));

    char *values = cJSON_GetObjectItem(json, "values")->valuestring;
    feature.setValues(std::string(values));

    char *type = cJSON_GetObjectItem(json, "type")->valuestring;
    feature.setType(std::string(type));

    int version = cJSON_GetObjectItem(json, "version")->valueint;
    feature.setVersion(version);

    cJSON_Delete(json);

    std::cout << "DeserializeFromStr" << std::endl;
    std::cout << feature.getCategory() << std::endl;
    std::cout << feature.getKey() << std::endl;
    std::cout << feature.getValues() << std::endl;
    std::cout << feature.getType() << std::endl;
    std::cout << feature.getVersion() << std::endl;
}

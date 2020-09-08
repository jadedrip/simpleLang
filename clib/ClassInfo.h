#pragma once
#include <stdint.h>
#include <string>
#include <map>
#include "Field.h"

class ClassType {
    const uint64_t id;
    std::string packageName;
    std::string className;
    std::map<std::string, Field> fields;

    ClassType* inherit = nullptr;   // ผฬณะ
};
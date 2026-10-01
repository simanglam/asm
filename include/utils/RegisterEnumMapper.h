#pragma once

#include <unordered_map>
#include <string>

#include "semantic/RegisterEnum.h"

class RegisterEnumMapper {
    static RegisterEnumMapper* hidden;
    RegisterEnumMapper();

    std::unordered_map<RegisterEnum, std::string> mapper;

public:
    static RegisterEnumMapper& getInstance();
    std::string& getRepr(RegisterEnum);
};
#pragma once

#include <unordered_map>
#include <string>

#include "semantic/InstructionEnum.h"

class InstructionEnumMapper {
    static InstructionEnumMapper* hidden;
    InstructionEnumMapper();

    std::unordered_map<InstructionEnum, std::string> mapper;

public:
    static InstructionEnumMapper& getInstance();
    std::string& getRepr(InstructionEnum);
};
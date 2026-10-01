#include "utils/InstructionEnumMapper.h"

using namespace std;

InstructionEnumMapper* InstructionEnumMapper::hidden = nullptr;

InstructionEnumMapper::InstructionEnumMapper() {
    mapper = {
        {ADD, "+"},
        {SUB, "-"},
        {AND, "&"},
        {OR, "|"},
        {ADDI, "+"},
        {LUI, "<< 16"},
        {MUL, "*"},
        {DIV, "/"},
        {REM, "&"},
        
        // Memory code
        {LW, "<-"},
        {SW, "->"},
        
        // Jump Code
        {BEQ, "jump if"},
        {J, "jump"},
        {JAL, "jump and link"},
        {JR, "jump register"},
        
        // Default Code
        {ERR, "ERR"}
    };
}

InstructionEnumMapper& InstructionEnumMapper::getInstance() {
    if (InstructionEnumMapper::hidden == nullptr)
        InstructionEnumMapper::hidden = new InstructionEnumMapper();
    return *InstructionEnumMapper::hidden;
}

std::string& InstructionEnumMapper::getRepr(InstructionEnum insEnum) {
    return mapper[insEnum];
}
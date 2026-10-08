#include "utils/InstructionEnumMapper.h"

using namespace std;

InstructionEnumMapper* InstructionEnumMapper::hidden = nullptr;

InstructionEnumMapper::InstructionEnumMapper() {
    mapper = {
        {ADD, "+"},
        {SUB, "-"},
        {AND, "&"},
        {OR, "|"},
        {XOR, "^"},
        {ADDI, "+"},
        {SLT, "<<"},
        {SLL, "<<"},
        {SRL, ">>"},
        {SRA, ">>"},
        {LUI, "<< 16"},
        {MUL, "*"},
        {MULH, "*"},
        {DIV, "/"},
        {REM, "&"},
        {ORI, "|"},
        
        // Memory code
        {LW, "<-"},
        {LB, "<-"},
        {LBU, "<-"},
        {LH, "<-"},
        {LHU, "<-"},
        {SW, "->"},
        {SB, "->"},
        {SH, "->"},
        
        // Jump Code
        {BEQ, "jump if"},
        {BNE, "jump if not"},
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
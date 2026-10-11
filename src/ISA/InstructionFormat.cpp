#include "ISA/InstructionFormat.h"

#include <unordered_map>

std::unordered_map<InstructionEnum, Format> InstructionFormatMapper = {
    {ADD, RFORMAT},
    {SUB, RFORMAT},
    {AND, RFORMAT},
    {OR, RFORMAT},
    {XOR, RFORMAT},
    {SLT, RFORMAT},
    {SLL, RFORMAT},
    {SRL, RFORMAT},
    {SRA, RFORMAT},
    {MUL, RFORMAT},
    {MULH, RFORMAT},
    {DIV, RFORMAT},

    {ADDI, IFORMAT},
    {ORI, IFORMAT},
    {LUI, IFORMAT},
    {REM, RFORMAT},
    
    // Memory code
    {LW, RFORMAT},
    {LB, RFORMAT},
    {LBU, RFORMAT},
    {LH, RFORMAT},
    {LHU, RFORMAT},

    {SW, RFORMAT},
    {SB, RFORMAT},
    {SH, RFORMAT},
    
    // Jump Code
    {BEQ, RFORMAT},
    {BNE, RFORMAT},
    {J, JFORMAT},
    {JAL, RFORMAT},
    {JR, RFORMAT}
};

Format InstructionEnumToFormat(InstructionEnum ins) {
    return InstructionFormatMapper[ins];
}
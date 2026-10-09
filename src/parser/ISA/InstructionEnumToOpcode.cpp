#include "ISA/InstructionEnumToOpcode.h"

std::unordered_map<InstructionEnum, int> InstructionToOpcodeMapper = {
    {ADD, 0x0},
    {SUB, 0x0},
    {AND, 0x0},
    {OR, 0x0},
    {XOR, 0x0},
    {SLT, 0x0},
    {SLL, 0x0},
    {SRL, 0x0},
    {SRA, 0x0},
    {MUL, 0x0},
    {MULH, 0x0},
    {DIV, 0x0},

    {ADDI, 0x001000},
    {ORI, 0x001101},
    {LUI, 0x001111},
    {REM, 0x0},
    
    // Memory code
    {LW, 0x100011},
    {LB, 0x100000},
    {LBU, 0x100100},
    {LH, 0x100001},
    {LHU, 0x100101},

    {SW, 0x101011},
    {SB, 0x101000},
    {SH, 0x101001},
    
    // Jump Code
    {BEQ, 0x000100},
    {BNE, 0x000101},
    {J, 0x000010},
    {JAL, 0x110000},
    {JR, 0x001000},
    
    // Default Code
    {ERR, 0x0}
};

int instructionEnumToOpcode(InstructionEnum ins) {
    return InstructionToOpcodeMapper[ins];
}
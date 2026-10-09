#include "ISA/InstructionEnumToOpcode.h"

std::unordered_map<InstructionEnum, int> InstructionToFunctMapper = {
    {ADD, 0x100000},
    {SUB, 0x100010},
    {AND, 0x100100},
    {OR, 0x100101},
    {XOR, 0x100110},
    {SLT, 0x101010},
    {SLL, 0x000000},
    {SRL, 0x000010},
    {SRA, 0x000011},
    {MUL, 0x011000},
    {MULH, 0x011001},
    {DIV, 0x011010},

    {ADDI, 0x0},
    {ORI, 0x0},
    {LUI, 0x0},
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
    {BEQ, 0x0},
    {BNE, 0x0},
    {J, 0x0},
    {JAL, 0x0},
    {JR, 0x001000},
    
    // Default Code
    {ERR, 0x0}
};

int instructionEnumToFunct(InstructionEnum ins) {
    return InstructionToFunctMapper[ins];
}
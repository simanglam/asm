#include "ISA/InstructionEnumToOpcode.h"

std::unordered_map<InstructionEnum, unsigned int> InstructionToFunctMapper = {
    {ADD, 0b100000},
    {SUB, 0b100010},
    {AND, 0b100100},
    {OR, 0b100101},
    {XOR, 0b100110},
    {SLT, 0b101010},
    {SLL, 0b000000},
    {SRL, 0b000010},
    {SRA, 0b000011},
    {MUL, 0b011000},
    {MULH, 0b011001},
    {DIV, 0b011010},

    {ADDI, 0b0},
    {ORI, 0b0},
    {LUI, 0b0},
    {REM, 0b0},
    
    // Memory code
    {LW, 0b100011},
    {LB, 0b100000},
    {LBU, 0b100100},
    {LH, 0b100001},
    {LHU, 0b100101},

    {SW, 0b101011},
    {SB, 0b101000},
    {SH, 0b101001},
    
    // Jump Code
    {BEQ, 0b0},
    {BNE, 0b0},
    {J, 0b0},
    {JAL, 0b0},
    {JR, 0b001000},
    
    // Default Code
    {ERR, 0b0}
};

int instructionEnumToFunct(InstructionEnum ins) {
    return InstructionToFunctMapper[ins];
}
#include "ISA/InstructionEnumToOpcode.h"

std::unordered_map<InstructionEnum, unsigned int> InstructionToOpcodeMapper = {
    {ADD, 0b0},
    {SUB, 0b0},
    {AND, 0b0},
    {OR, 0b0},
    {XOR, 0b0},
    {SLT, 0b0},
    {SLL, 0b0},
    {SRL, 0b0},
    {SRA, 0b0},
    {MUL, 0b0},
    {MULH, 0b0},
    {DIV, 0b0},

    {ADDI, 0b001000},
    {ORI, 0b001101},
    {LUI, 0b001111},
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
    {BEQ, 0b000100},
    {BNE, 0b000101},
    {J, 0b000010},
    {JAL, 0b110000},
    {JR, 0b001000},
    
    // Default Code
    {ERR, 0b0}
};

unsigned int instructionEnumToOpcode(InstructionEnum ins) {
    return InstructionToOpcodeMapper[ins];
}
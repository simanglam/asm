#pragma once

enum InstructionEnum {
    // Arithmetic Code
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    SLT,
    SLL,
    SRL,
    SRA,
    MUL,
    MULH,
    DIV,

    ADDI,
    LUI,
    REM,
    
    // Memory code
    LW,
    LB,
    LBU,
    LH,
    LHU,

    SW,
    SB,
    SH,
    
    // Jump Code
    BEQ,
    BNE,
    J,
    JAL,
    JR,
    
    // Default Code
    ERR
};
#pragma once

enum InstructionEnum {
    // Arithmetic Code
    ADD,
    SUB,
    AND,
    OR,
    ADDI,
    LUI,
    MUL,
    DIV,
    REM,
    
    // Memory code
    LW,
    SW,
    
    // Jump Code
    BEQ,
    J,
    JAL,
    JR,
    
    // Default Code
    ERR
};
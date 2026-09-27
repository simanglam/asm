#include "semantic/InstructionEnum.h"
#include "string"

InstructionEnum InstructionToEnum(std::string text) {
    if (text == "ADD") {
        return ADD;
    }
    if (text == "SUB") {
        return SUB;
    }
    if (text == "AND") {
        return AND;
    }
    if (text == "OR") {
        return OR;
    }
    if (text == "ADDI") {
        return ADDI;
    }
    if (text == "LUI") {
        return LUI;
    }
    if (text == "MUL") {
        return MUL;
    }
    if (text == "DIV") {
        return DIV;
    }
    if (text == "REM") {
        return REM;
    }
    
    // Memory code
    if (text == "LW") {
        return LW;
    }
    if (text == "SW") {
        return SW;
    }
    
    // Jump Code
    if (text == "BEQ") {
        return BEQ;
    }
    if (text == "J") {
        return J;
    }
    if (text == "JAL") {
        return JAL;
    }
    if (text == "JR") {
        return JR;
    }
    
    // Default Code
    if (text == "ERR") {
        return ERR;
    }
    
}
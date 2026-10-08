#include "semantic/InstructionEnum.h"
#include "string"

InstructionEnum InstructionToEnum(std::string text) {
    if (text == "ADD"){
		return ADD;
	}
    if (text == "SUB"){
		return SUB;
	}
    if (text == "AND"){
		return AND;
	}
    if (text == "OR"){
		return OR;
	}
    if (text == "XOR"){
		return XOR;
	}
    if (text == "SLT"){
		return SLT;
	}
    if (text == "SLL"){
		return SLL;
	}
    if (text == "SRL"){
		return SRL;
	}
    if (text == "SRA"){
		return SRA;
	}
    if (text == "MUL"){
		return MUL;
	}
    if (text == "MULH"){
		return MULH;
	}
    if (text == "DIV"){
		return DIV;
	}

    if (text == "ADDI"){
		return ADDI;
	}
    if (text == "LUI"){
		return LUI;
	}
    if (text == "REM"){
		return REM;
	}
    
    // Memory code
    if (text == "LW"){
		return LW;
	}
    if (text == "LB"){
		return LB;
	}
    if (text == "LBU"){
		return LBU;
	}
    if (text == "LH"){
		return LH;
	}
    if (text == "LHU"){
		return LHU;
	}

    if (text == "SW"){
		return SW;
	}
    if (text == "SB"){
		return SB;
	}
    if (text == "SH"){
		return SH;
	}
    
    // Jump Code
    if (text == "BEQ"){
		return BEQ;
	}
    if (text == "BNE"){
		return BNE;
	}
    if (text == "J"){
		return J;
	}
    if (text == "JAL"){
		return JAL;
	}
    if (text == "JR"){
		return JR;
	}
    
    // Default Code
    if (text == "ERR") {
        return ERR;
    }
    
}
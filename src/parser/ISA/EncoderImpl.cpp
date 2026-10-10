#include "ISA/EncoderImpl.h"

#include "ISA/InstructionFormat.h"
#include "ISA/InstructionEnumToFunct.h"
#include "ISA/InstructionEnumToOpcode.h"

#include <vector>
#include <iostream>
#include "parser/ASTs/Operand.h"

using namespace std;

unsigned int EncoderImpl::encode(Instruction* ins) {
    switch (InstructionEnumToFormat(ins->getEnum())) {
        case RFORMAT:
            return encode_r(ins);
        case IFORMAT:
            return encode_i(ins);
        default:
            return encode_j(ins);
    }
}

unsigned int EncoderImpl::encode_r(Instruction* ins) {
    unsigned int result = 0;
    vector<Operand*> operands = ins->getOperands();
    if (operands.size() != 3 && operands.size() != 1) {
        cerr << "Unexpect operands size " << operands.size() << " for instruction " << ins->getEnum() << " when encoding r format" << endl;
        return 0;
    }

    unsigned int rd = 0, rs = 0, rt = 0, opcode = 0, funct = 0, shamt = 0;
    opcode = instructionEnumToOpcode(ins->getEnum());
    funct = instructionEnumToFunct(ins->getEnum());

    if (operands.size() == 3) {
        rd = any_cast<unsigned int>(operands[0]->accept(operandEncoder));
        rs = any_cast<unsigned int>(operands[1]->accept(operandEncoder));
        rt = any_cast<unsigned int>(operands[2]->accept(operandEncoder));
    }

    else {
        rs = any_cast<unsigned int>(operands[0]->accept(operandEncoder));
    }

    result |= opcode << 26;

    result |= rs << 21;

    result |= rt << 16;

    cout << rs << endl;
    cout << rt << endl;
    cout << rd << endl;
    cout << opcode << endl;
    cout << funct << endl;

    if (opcode == SLT || opcode == SLL || opcode == SRA || opcode == SRL) {
        result |= rd << 11;
        result |= rt << 6;
    }
    else {
        result |= rd << 11;
    }
    result |= funct;
    return result;
}

unsigned int EncoderImpl::encode_i(Instruction* ins) {
    unsigned int result = 0;
    vector<Operand*> operands = ins->getOperands();
    if (operands.size() < 2) {
        cerr << "Unexpect operands size for instruction " << ins->getEnum() << " when encoding i format" << endl;
        return 0;
    }

    
    unsigned int rs = 0, rt = 0, opcode = 0, immediate = 0;
    
    if (operands.size() == 3) {
        rt = any_cast<unsigned int>(operands[0]->accept(operandEncoder));
        rs = any_cast<unsigned int>(operands[1]->accept(operandEncoder));
        immediate = any_cast<unsigned int>(operands[2]->accept(operandEncoder));
    }
    else {
        rt = any_cast<unsigned int>(operands[0]->accept(operandEncoder));
        // rs = any_cast<int>(operands[1]->accept(operandEncoder));
        immediate = any_cast<unsigned int>(operands[1]->accept(operandEncoder));
    }


    result |= instructionEnumToOpcode(ins->getEnum());
    result <<= 5;

    result |= rs;
    result <<= 5;

    result |= rt;
    result <<= 16;

    result |= immediate;

    return result;
}

unsigned int EncoderImpl::encode_j(Instruction* ins) {
    int result = 0;
    vector<Operand*> operands = ins->getOperands();
    if (operands.size() != 1) {
        cerr << "Unexpect operands size for instruction " << ins->getEnum() << " when encoding j format" << endl;
        return 0;
    }

    unsigned int opcode = 0, target = 0;

    target = any_cast<unsigned int>(operands[0]->accept(operandEncoder));
    
    result |= instructionEnumToOpcode(ins->getEnum());
    result <<= 26;

    
    result |= target;
    return result;
}

#include "ISA/OperandEncoder.h"

#include <iostream>
#include "utils/InstructionEnumMapper.h"
#include "utils/RegisterEnumMapper.h"
#include "ISA/RegisterEnumEncode.h"

using namespace std;

any OperandEncoder::visitProgram(Program* ctx) {
    return 0;
}

any OperandEncoder::visitDirective(Directive* ctx) {
    return 0;
}

any OperandEncoder::visitInstruction(Instruction* ctx) {
    return 0;
}

any OperandEncoder::visitOperand(Operand* ctx) {
    return 0;
}

any OperandEncoder::visitImmediate(Immediate* ctx) {
    return (unsigned int)ctx->getVal();
}

any OperandEncoder::visitRegister(Register* ctx) {
    return registerEnumEncode(ctx->getEnum());
}

any OperandEncoder::visitLabel(Label* ctx) {
    return (unsigned int)ctx->encode() << 2;
}

any OperandEncoder::visitLabelNode(LabelNode* ctx) {
    return 0;
}
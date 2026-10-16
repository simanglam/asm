#include "passes/Codegen.h"

#include <iostream>
#include "utils/InstructionEnumMapper.h"
#include "utils/RegisterEnumMapper.h"

using namespace std;

Codegen::Codegen(Encoder* _encoder): encoder(_encoder) {
    assembleContext = AssembleContext::getInstance();
    result = new list<Bytes*>();
}

Codegen::~Codegen() {
    delete encoder;
}

any Codegen::visitProgram(Program* ctx) {
    for (auto node : ctx->getBody())
        node->accept(*this);
    return result;
}

any Codegen::visitDirective(Directive* ctx) {
    if (ctx->getText() == "word")
        result->push_back(new Bytes(ctx->getVal(), 4));
    if (ctx->getText() == "half")
        result->push_back(new Bytes(ctx->getVal(), 2));
    if (ctx->getText() == "byte")
        result->push_back(new Bytes(ctx->getVal(), 1));
    return 0;
}

any Codegen::visitInstruction(Instruction* ctx) {
    result->push_back(encoder->encode(ctx));
    return 0;
}

any Codegen::visitOperand(Operand* ctx) {
    return 0;
}

any Codegen::visitImmediate(Immediate* ctx) {
    return 0;
}

any Codegen::visitRegister(Register* ctx) {
    return 0;
}

any Codegen::visitLabel(Label* ctx) {
    return 0;
}

any Codegen::visitLabelNode(LabelNode* ctx) {
    return 0;
}
#include "passes/Codegen.h"

#include <iostream>
#include "utils/InstructionEnumMapper.h"
#include "utils/RegisterEnumMapper.h"

using namespace std;

Codegen::Codegen(Encoder* _encoder): encoder(_encoder) {

}

Codegen::~Codegen() {
    delete encoder;
}

any Codegen::visitProgram(Program* ctx) {
    list<unsigned int>* result = new list<unsigned int>();
    for (auto node : ctx->getBody())
        result->push_back(any_cast<unsigned int>(node->accept(*this)));
    return result;
}

any Codegen::visitDirective(Directive* ctx) {
    cout << "Directive: " << ctx->getText() << " " << ctx->getVal() << endl;
    return 0;
}

any Codegen::visitInstruction(Instruction* ctx) {
    return encoder->encode(ctx);
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
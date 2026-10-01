#include "passes/ASTPrinter.h"

#include <iostream>
#include "utils/InstructionEnumMapper.h"
#include "utils/RegisterEnumMapper.h"

using namespace std;

any ASTPrinter::visitProgram(Program* ctx) {
    for (auto node : ctx->getBody())
        node->accept(*this);
    return nullptr;
}

any ASTPrinter::visitDirective(Directive* ctx) {
    cout << "Directive: " << ctx->getText() << " " << ctx->getVal() << endl;
    return nullptr;
}

any ASTPrinter::visitInstruction(Instruction* ctx) {
    cout << "Instruction: ";
    InstructionEnumMapper& mapper = InstructionEnumMapper::getInstance();
    if (ctx->getOperands().size() == 3)
        cout 
            << any_cast<string>(ctx->getOperands().at(0)->accept(*this)) 
            << " = "
            << any_cast<string>(ctx->getOperands().at(1)->accept(*this)) << " "
            << mapper.getRepr(ctx->getEnum()) 
            << " " << any_cast<string>(ctx->getOperands().at(2)->accept(*this))
            << endl;
    else if (ctx->getOperands().size() == 2)
        cout 
            << any_cast<string>(ctx->getOperands().at(0)->accept(*this)) << " "
            << mapper.getRepr(ctx->getEnum()) 
            << " " << any_cast<string>(ctx->getOperands().at(1)->accept(*this))
            << endl;
    else if (ctx->getOperands().size() == 1)
        cout 
            << mapper.getRepr(ctx->getEnum()) << " "
            << any_cast<string>(ctx->getOperands().at(0)->accept(*this))
            << endl;
    return nullptr;
}

any ASTPrinter::visitOperand(Operand* ctx) {
    
    return nullptr;
}

any ASTPrinter::visitImmediate(Immediate* ctx) {
    return to_string(ctx->getVal());
}

any ASTPrinter::visitRegister(Register* ctx) {
    RegisterEnumMapper& mapper = RegisterEnumMapper::getInstance();
    return mapper.getRepr(ctx->getEnum());
}

any ASTPrinter::visitLabel(Label* ctx) {
    return ctx->getId();
    return nullptr;
}
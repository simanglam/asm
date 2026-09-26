#include "ASTs/ASTBuilder.h"


std::any ASTBuilder::visitProgram(asmParser::ProgramContext *context) {
    for (auto a : context->inst())
        this->visitInst(a);
    return ;
}

std::any ASTBuilder::visitInst(asmParser::InstContext *context) {
    if (context->directive() != nullptr)
        return this->visitDirective(context->directive());
    else
        return this->visitInstruction(context->instruction());
    return nullptr;
}

std::any ASTBuilder::visitDirective(asmParser::DirectiveContext *context) {
    std::cout << context->toStringTree() << std::endl;
    return nullptr;
}

std::any ASTBuilder::visitInstruction(asmParser::InstructionContext *context) {
    return nullptr;
}

std::any ASTBuilder::visitOpreand(asmParser::OpreandContext *context) {
    return nullptr;
}
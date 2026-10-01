#include <list>
#include <vector>

#include "parser/ASTs/ASTBuilder.h"
#include "parser/ASTs/Instruction.h"
#include "parser/ASTs/Directive.h"
#include "parser/ASTs/Operand.h"
#include "parser/ASTs/Program.h"

#include "semantic/InstructionEnum.h"

#include "utils/InstructionToEnum.h"
#include "utils/RegisterToEnum.h"

using namespace std;


std::any ASTBuilder::visitProgram(asmParser::ProgramContext *context) {
    list<AST*> body;
    for (auto a : context->inst())
        body.push_back(
            any_cast<AST*>(this->visitInst(a))
        );
    return new Program(body);
}

std::any ASTBuilder::visitInst(asmParser::InstContext *context) {
    if (context->directive() != nullptr)
        return this->visitDirective(context->directive());
    else
        return this->visitInstruction(context->instruction());
    return nullptr;
}

std::any ASTBuilder::visitDirective(asmParser::DirectiveContext *context) {
    int val = 0;
    if (context->val)
        val = stoi(context->val->getText());
    return (AST*)new Directive(
        context->id->getText(),
        val
    );
}

std::any ASTBuilder::visitInstruction(asmParser::InstructionContext *context) {
    vector<Operand*> operands;
    for (auto op : context->operands) {
        operands.push_back(
            any_cast<Operand*>(
                this->visitOpreand(op)
            )
        );
    }

    return (AST*)new Instruction(
        InstructionToEnum(context->ID()->getText()),
        operands
    );
    
}

std::any ASTBuilder::visitOpreand(asmParser::OpreandContext *context) {
    if (context->REGISTER())
        return (Operand*)new Register(
            RegisterToEnum(context->REGISTER()->getText())
        );
    else if (context->INTEGER())
        return (Operand*)new Immediate(
            stoi(context->INTEGER()->getText())
        );

    return (Operand*)new Label(
        0, context->ID()->getText()
    );
}
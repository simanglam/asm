#pragma once

#include "parser/ASTs/ASTVisitor.h"

#include "utils/AssembleContext.h"

class LayoutPass: ASTVisitor<std::any> {
    unsigned int counter;
    AssembleContext* assembleContext;
public:
    std::any visitProgram(Program*) override;
    std::any visitDirective(Directive*) override;
    std::any visitInstruction(Instruction*) override;
    std::any visitOperand(Operand*) override;
    std::any visitImmediate(Immediate*) override;
    std::any visitRegister(Register*) override;
    std::any visitLabel(Label*) override;
    std::any visitLabelNode(LabelNode*) override;
};
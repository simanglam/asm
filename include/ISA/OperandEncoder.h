#pragma once

#include "parser/ASTs/ASTVisitor.h"

class OperandEncoder: public ASTVisitor<std::any> {
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
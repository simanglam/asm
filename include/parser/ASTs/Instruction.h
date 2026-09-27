#pragma once
#include <string>
#include <vector>
#include "AST.h"
#include "parser/ASTs/Operand.h"
#include "semantic/InstructionEnum.h"

class Instruction: AST {
    InstructionEnum instruction;
    std::vector<Operand*> operands;
public:
    Instruction(InstructionEnum, std::vector<Operand*>);
    std::any accept(ASTVisitor<std::any>&) override;
};
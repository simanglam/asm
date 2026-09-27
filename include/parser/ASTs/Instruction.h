#pragma once
#include <string>
#include <vector>
#include "AST.h"
#include "parser/ASTs/Operand.h"

class Instruction: AST {
    std::string text;
    std::vector<Operand*> operands;
public:
    Instruction(std::string, std::vector<Operand*>);
    std::any accept(ASTVisitor<std::any>&) override;
};
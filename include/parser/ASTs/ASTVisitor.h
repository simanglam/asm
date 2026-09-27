#pragma once

#include "parser/ASTs/AST.h"
#include "parser/ASTs/Directive.h"
#include "parser/ASTs/Instruction.h"
#include "parser/ASTs/Operand.h"
#include "parser/ASTs/Program.h"

template<class t>
class ASTVisitor {
public:
    virtual t visitProgram(Program*) = 0;
    virtual t visitDirective(Directive*) = 0;
    virtual t visitInstruction(Instruction*) = 0;
    virtual t visitOperand(Operand*) = 0;
};
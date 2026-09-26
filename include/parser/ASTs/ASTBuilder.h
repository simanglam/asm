#pragma once
#include "asmVisitor.h"
#include "AST.h"

class ASTBuilder: asmVisitor {
public:
    std::any visitProgram(asmParser::ProgramContext *context);

    std::any visitDirective(asmParser::DirectiveContext *context);

    std::any visitInstruction(asmParser::InstructionContext *context);

    std::any visitOpreand(asmParser::OpreandContext *context);
    
    std::any visitInst(asmParser::InstContext *context);
};
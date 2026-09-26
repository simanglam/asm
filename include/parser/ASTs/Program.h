#pragma once
#include <list>
#include "AST.h"

class Program: AST {
    std::list<AST*> body;
public:
    Program(std::list<AST*>);
    std::any accept(ASTVisitor<std::any>&) override;
};
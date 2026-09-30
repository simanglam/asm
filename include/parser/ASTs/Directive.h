#pragma once
#include <string>
#include "AST.h"

class Directive: AST {
    std::string text;
    int val;
public:
    Directive(std::string, int);
    std::any accept(ASTVisitor<std::any>&) override;

    int getVal() const;
    std::string getText() const;
};
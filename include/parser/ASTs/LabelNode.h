#pragma once
#include <string>
#include "parser/ASTs/AST.h"

class LabelNode : AST {
    std::string text;
public:
    LabelNode(std::string);
    std::any accept(ASTVisitor<std::any>& visitor) override;
    
    std::string getText();
};
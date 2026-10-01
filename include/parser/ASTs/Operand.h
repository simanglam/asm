#pragma once

#include "AST.h"
#include "semantic/RegisterEnum.h"
class Operand: AST {
public:
    virtual ~Operand() = default;
    virtual int encode() = 0;
    std::any accept(ASTVisitor<std::any>&) = 0;
};
    

class Register: Operand {
    RegisterEnum registerEnum;
public:
    Register(RegisterEnum);
    int encode() override;
    std::any accept(ASTVisitor<std::any>&) override;

    RegisterEnum getEnum();
};
    

class Immediate: Operand {
    int val;
public:
    Immediate(int);
    int encode() override;
    std::any accept(ASTVisitor<std::any>&) override;

    int getVal();
};
    

class Label: Operand {
    std::string id;
    int offset;
public:
    Label(int, std::string);
    int encode() override;
    std::any accept(ASTVisitor<std::any>&) override;

    std::string getId();
};
    

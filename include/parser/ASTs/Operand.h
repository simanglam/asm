#pragma once

#include "AST.h"
#include "semantic/RegisterEnum.h"
class Operand: AST {
public:
    virtual ~Operand() = default;
    virtual int encode() = 0;
    std::any accept(ASTVisitor<std::any>& visitor) {return this->encode();}
};
    

class Register: Operand {
    RegisterEnum registerEnum;
public:
    Register(RegisterEnum);
    int encode() override;
};
    

class Immediate: Operand {
    int val;
public:
    Immediate(int);
    int encode() override;
};
    

class Label: Operand {
    int offset;
public:
    Label(int);
    int encode() override;
};
    

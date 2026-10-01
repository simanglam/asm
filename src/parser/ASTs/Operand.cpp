#include "parser/ASTs/Operand.h"


Register::Register(RegisterEnum _registerEnum): registerEnum(_registerEnum) { }

std::any Register::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitRegister(this);
}

int Register::encode() {
    return 0;
}

RegisterEnum Register::getEnum() {
    return registerEnum;
}

Immediate::Immediate(int _val): val(_val) {}
int Immediate::encode() {
    return val;
}

int Immediate::getVal() {
    return val;
}

std::any Immediate::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitImmediate(this);
}
    
Label::Label(int _offset, std::string _id): offset(_offset), id(_id) {}

int Label::encode() {
    return offset;
}

std::any Label::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitLabel(this);
}

std::string Label::getId() {
    return id;
}
    

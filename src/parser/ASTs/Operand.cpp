#include "parser/ASTs/Operand.h"


Register::Register(RegisterEnum _registerEnum): registerEnum(_registerEnum) { }

int Register::encode() {
    return 0;
}

Immediate::Immediate(int _val): val(_val) {}
int Immediate::encode() {
    return val;
}
    
Label::Label(int _offset): offset(_offset) {}

int Label::encode() {
    return offset;
}
    

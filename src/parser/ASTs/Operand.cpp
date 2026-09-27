#include "parser/ASTs/Operand.h"
class Operand: AST {
public:
    virtual ~Operand() = default;
    virtual int encode() = 0;
};
    



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
    

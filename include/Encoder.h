#pragma once
#include "parser/ASTs/Instruction.h"

class Encoder {
public:
    virtual ~Encoder() {};
    virtual unsigned int encode(Instruction*) = 0;
};
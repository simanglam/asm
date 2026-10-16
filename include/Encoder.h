#pragma once
#include "utils/Bytes.h"
#include "parser/ASTs/Instruction.h"

class Encoder {
public:
    virtual ~Encoder() {};
    virtual Bytes* encode(Instruction*) = 0;
};
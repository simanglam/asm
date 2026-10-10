#pragma once

#include "Encoder.h"
#include "ISA/OperandEncoder.h"

class EncoderImpl: public Encoder {
    OperandEncoder operandEncoder;

    unsigned int encode_r(Instruction*);
    unsigned int encode_i(Instruction*);
    unsigned int encode_j(Instruction*);

public:
    // EncoderImpl();
    unsigned int encode(Instruction*);
};
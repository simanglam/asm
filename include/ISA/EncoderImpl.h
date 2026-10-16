#pragma once

#include "Encoder.h"
#include "ISA/OperandEncoder.h"

class EncoderImpl: public Encoder {
    OperandEncoder operandEncoder;

    Bytes* encode_r(Instruction*);
    Bytes* encode_i(Instruction*);
    Bytes* encode_j(Instruction*);

public:
    // EncoderImpl();
    Bytes* encode(Instruction*);
};
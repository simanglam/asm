#pragma once

#include "semantic/InstructionEnum.h"

enum Format {
    RFORMAT,
    IFORMAT,
    JFORMAT
};

Format InstructionEnumToFormat(InstructionEnum);
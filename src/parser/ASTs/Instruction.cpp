#include "parser/ASTs/Instruction.h"

using namespace std;


Instruction::Instruction(InstructionEnum _instruction, std::vector<Operand*> _operands): instruction(_instruction), operands(_operands) { }

std::any Instruction::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitInstruction(this);
}

InstructionEnum Instruction::getEnum() const {
    return instruction;
}

std::vector<Operand*>& Instruction::getOperands() {
    return operands;
}
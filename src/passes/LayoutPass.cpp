#include "passes/LayoutPass.h"

using namespace std;

any LayoutPass::visitProgram(Program*) {}

any LayoutPass::visitDirective(Directive*) {}

any LayoutPass::visitInstruction(Instruction*) {}

any LayoutPass::visitOperand(Operand*) {}

any LayoutPass::visitImmediate(Immediate*) {}

any LayoutPass::visitRegister(Register*) {}

any LayoutPass::visitLabel(Label*) {}

any LayoutPass::visitLabelNode(LabelNode*) {}
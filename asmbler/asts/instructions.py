from .astnode import ASTNode
from ..util import FunctCode, Opcodes
from ..operands import Operand

from dataclasses import dataclass

@dataclass
class Instruction(ASTNode):
    funct: FunctCode
    opcode: Opcodes
    oprands: list[Operand]
    
    def visit(self, visitor):
        return visitor.visitInstruction(self)
    
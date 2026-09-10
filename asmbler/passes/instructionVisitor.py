from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..asts import ASTNode, Instruction, LabelNode



class InstructionVisitor:
    def __init__(self) -> None:
        pass

    def visitInstruction(self, abstractInstruction: Instruction):
        pass

    def visitLabel(self, abstractInstruction: LabelNode):
        pass
        

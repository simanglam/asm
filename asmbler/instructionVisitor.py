from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .asts.astnode import ASTNode



class InstructionVisitor:
    def __init__(self) -> None:
        pass

    def visit_arithmetic(self, abstractInstruction: ASTNode):
        pass

    def visit_memory_access(self, abstractInstruction: ASTNode):
        pass

    def visit_control(self, abstractInstruction: ASTNode):
        pass
        

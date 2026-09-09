from dataclasses import dataclass

from .astnode import ASTNode

@dataclass
class Label(ASTNode):
    text: str
    
    def visit(self, visitor):
        pass
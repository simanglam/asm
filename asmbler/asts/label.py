from dataclasses import dataclass

from .astnode import ASTNode

@dataclass
class LabelNode(ASTNode):
    text: str
    
    def visit(self, visitor):
        pass
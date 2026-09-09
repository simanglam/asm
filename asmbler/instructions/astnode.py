from typing import Self
from ..instructionVisitor import InstructionVisitor
from abc import ABC, abstractmethod

from dataclasses import dataclass, field

class ASTNode(ABC):
    
    @abstractmethod
    def visit(self, visitor: InstructionVisitor):
        raise NotImplementedError("This is an abstract class. Why?")
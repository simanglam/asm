from abc import ABC, abstractmethod
from dataclasses import dataclass
from ..util import RegisterEnum

class Operand(ABC):
    
    @abstractmethod
    def toByteStr(self, visitor) -> str:
        raise RuntimeError("?")
    
@dataclass
class Register(Operand):
    register: RegisterEnum
    def toByteStr(self, visitor) -> str:
        return "1"
    
@dataclass
class Immediate(Operand):
    val: int
    def toByteStr(self, visitor) -> str:
        return f"{self.val:x}"
    
@dataclass
class Label(Operand):
    target: str
    def toByteStr(self, visitor) -> str:
        return self.target
    

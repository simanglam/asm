
from .util import FunctCode, Opcodes, RegisterEnum
from .operands import Operand, Register, Immediate, Label

class Encoder():
    def __init__(self):
        pass
    
    
    def emitI(self, opcodes: Opcodes, funct: FunctCode, rs: RegisterEnum, rt: RegisterEnum) -> bytes:
        pass
    
    def emitR() -> bytes:
        pass
        
    def emitJ() -> bytes:
        pass
from enum import StrEnum, auto

class Opcodes(StrEnum):
    # Arithmetic Code
    ADD = auto()
    SUB = auto()
    AND = auto()
    OR = auto()
    ADDI = auto()
    LUI = auto()
    MUL= auto()
    DIV = auto()
    REM = auto()
    
    # Memory code
    LW = auto()
    SW = auto()
    
    # Jump Code
    BEQ = auto()
    J = auto()
    JAL = auto()
    JR = auto()
    
    # Default Code
    ERR = auto()
    
class OpcodeHelper:
    @staticmethod
    def strToOpcode(literal: str) -> Opcodes:
        try:
            return Opcodes[literal]
        except:
            return Opcodes["ERR"]
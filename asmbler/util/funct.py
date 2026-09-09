from enum import StrEnum, auto

class FunctCode(StrEnum):
    ADD = auto()
    SUB = auto()
    AND = auto()
    OR = auto()
    MUL = auto()
    DIV = auto()
    
    ERR = auto()
    

class FunctHelper:
    @staticmethod
    def strToArithFunct(literal: str) -> FunctCode:
        try:
            return FunctCode[literal]
        except:
            return FunctCode["ERR"]
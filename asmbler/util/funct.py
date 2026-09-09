from enum import StrEnum

class FunctCode(StrEnum):
    ADD = "100000"
    SUB = "100010"
    AND = "100100"
    OR = "100101"
    MUL = "011000"
    DIV = "011010"
    
    ERR = "000000"
    

class FunctHelper:
    @staticmethod
    def strToArithFunct(literal: str) -> FunctCode:
        try:
            return FunctCode[literal]
        except:
            return FunctCode["ERR"]
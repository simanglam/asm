from enum import Enum, auto

class TokenType(Enum):
    EOF = auto()
    ID = auto()
    REG = auto()
    COMMA = auto()
    PERIOD = auto()
    LEFT_PAR = auto()
    RIGHT_PAR = auto()
    CONSTANT = auto()

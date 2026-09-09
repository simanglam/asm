from typing import Self

from .tokenType import TokenType


class Token:
    def __init__(self, type: TokenType, str_literal: str = "", constant: int = 0, line: int = 0) -> None:
        self.type = type
        self.str_literal = str_literal
        self.constant = constant
        self.line = line
        
    def getLiteral(self) -> str:
        return self.str_literal

    def __str__(self) -> str:
        return f"Token: {self.type.name}\n\tliteral: {self.str_literal}\n\tvalue: {self.constant}\n\tat line: {self.line}"
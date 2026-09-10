from copy import copy
from typing import Self
from .token import Token
from .tokenType import TokenType

class Tokenizer:
    def __init__(self, file_name: str) -> None:
        self.file_name = file_name
        self.file = open(self.file_name, "r")
        self.current_token: Token = Token(TokenType.EOF)
        self.next_token: Token = Token(TokenType.EOF)
        
        self.current_char: str = ' '
        self.next_char: str = ' '
        
        self.line: int = 0

        self.consume()
        self.consume()

    def __del__(self):
        self.file.close()

    def consume(self) -> Token:
        self.current_token = copy(self.next_token)
        

        while self.current_char.isspace() and self.next_char != "":
            self.current_char = self.next_char
            self.next_char = self.file.read(1)

        buffer = ""
        match self.current_char:
            case ",":
                self.next_token = Token(TokenType.COMMA, ",")
                self.current_char = self.next_char
                self.next_char = self.file.read(1)
            case ".":
                self.next_token = Token(TokenType.PERIOD, ".")
                self.current_char = self.next_char
                self.next_char = self.file.read(1)
            case _:
                if self.current_char.isdigit():
                    while self.current_char.isdigit():
                        buffer += self.current_char
                        self.current_char = self.next_char
                        self.next_char = self.file.read(1)    
                
                    self.next_token = Token(TokenType.CONSTANT, buffer, int(buffer))
        
                elif self.current_char.isalpha():
                    if self.current_char == "r" and self.next_char.isdigit():
                        buffer += self.current_char
                        self.current_char = self.next_char
                        self.next_char = self.file.read(1)

                        while self.current_char.isdigit() and self.next_char != "":
                            buffer += self.current_char
                            self.current_char = self.next_char
                            self.next_char = self.file.read(1)
                
                            self.next_token = Token(TokenType.REG, buffer)
                
                    else:
                        while (self.current_char.isalpha() or self.current_char.isdigit()) and self.next_char != "":
                            buffer += self.current_char
                            self.current_char = self.next_char
                            self.next_char = self.file.read(1)
                
                        self.next_token = Token(TokenType.ID, buffer)
        if (self.next_char == ""):
            self.next_token = Token(TokenType.EOF)
        return self.current_token

    def peek(self) -> Token:
        return self.current_token

    def match(self, type: TokenType) -> bool:
        return self.current_token is not None and type == self.current_token.type
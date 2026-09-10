import re
from tkinter import NO
from typing import Self, Generator, Set

from asmbler.asts.label import LabelNode
from asmbler.operands import Label, Immediate, Register
from asmbler.operands.operand import Operand
from asmbler.util.funct import FunctHelper
from asmbler.util.opcode import OpcodeHelper

from .token import Token
from .tokenType import TokenType
from .tokenizer import Tokenizer

from .asts import ASTNode, Instruction

from .util import RegisterHelper


instrustion_sets: list[Set[str]] = [
    {"ADD", "ADDI", "SUB", "AND", "OR", "LUI", "BEQ", "MUL", "DIV", "LW", "SW"}, # three address
    {" "},
    {"J", "JAL", "JR"}
]

class Parser:
    def __init__(self, file: str) -> None:
        self.tokenizer: Tokenizer = Tokenizer(file)
        self.labelLocation: dict[str, int] = {}
    
    def parse(self) -> Generator[ASTNode, None, None]:
        while not self.tokenizer.match(TokenType.EOF):

            if self.tokenizer.match(TokenType.PERIOD):
                yield self.parseLabel()
            
            else:
                
                    
                if self.tokenizer.peek().str_literal in instrustion_sets[0]:
                    # TODO: Replace with function call
                    yield self.parseThreeAddress() 
                    
                elif self.tokenizer.peek().str_literal in instrustion_sets[1]:
                    # TODO: Replace with function call
                    yield self.parseTwoAddress()
                
                elif self.tokenizer.peek().str_literal in instrustion_sets[2]:
                    yield self.parseOneAddress()
                else:
                    # TODO: Panic and recover
                    self.panicAndRecover()
            self.tokenizer.consume()
                    
    def parseOneAddress(self) -> ASTNode:
        id = self.tokenizer.current_token.getLiteral()
        self.tokenizer.consume()
        if (self.tokenizer.match(TokenType.REG)):
            return Instruction(
                FunctHelper.strToArithFunct(id),
                OpcodeHelper.strToOpcode(id),
                [
                    Register(RegisterHelper.strToRigisterEnum(self.tokenizer.current_token.getLiteral()))
                ]
            )
        return Instruction(
            FunctHelper.strToArithFunct(id),
                OpcodeHelper.strToOpcode(id),
                [Label(self.tokenizer.current_token.getLiteral())]
        )
            
    
    def parseTwoAddress(self) -> ASTNode:
        id = self.tokenizer.current_token.getLiteral()
        self.tokenizer.consume()
        
        operands = []
        
        for i in range(2):
            operands.append(self.parseOperand())
            if not self.tokenizer.match(TokenType.COMMA) and i != 1:
                return self.panicAndRecover()
            self.tokenizer.consume()

            
        return Instruction(
            FunctHelper.strToArithFunct(id),
                OpcodeHelper.strToOpcode(id),
                operands
        )
    
    def parseOperand(self) -> Operand:
        val: Operand | None = None
        if self.tokenizer.match(TokenType.REG):
            val = Register(RegisterHelper.strToRigisterEnum(self.tokenizer.current_token.getLiteral()))
        elif self.tokenizer.match(TokenType.ID):
            val = Label(self.tokenizer.current_token.getLiteral())
        elif self.tokenizer.match(TokenType.CONSTANT):
            val = Immediate(int(self.tokenizer.current_token.getLiteral()))
        else:
            self.panicAndRecover()
            
        return val
            
            
        
    def parseThreeAddress(self) -> ASTNode:
        id = self.tokenizer.current_token.getLiteral()
        self.tokenizer.consume()
                
        operands = []
        
        
        operands.append(self.parseOperand())
        self.tokenizer.consume()
        if not self.tokenizer.match(TokenType.COMMA):
            return self.panicAndRecover()
        self.tokenizer.consume()
        
        operands.append(self.parseOperand())
        self.tokenizer.consume()
        if not self.tokenizer.match(TokenType.COMMA):
            return self.panicAndRecover()
        self.tokenizer.consume()
        
        operands.append(self.parseOperand())                      
            
        return Instruction(
            FunctHelper.strToArithFunct(id),
            OpcodeHelper.strToOpcode(id),
            operands
        )
        
    def parseLabel(self) -> ASTNode:
        self.tokenizer.consume()
        return LabelNode(self.tokenizer.current_token.getLiteral())
    
    def panicAndRecover(self) -> ASTNode:
        print(self.tokenizer.current_token)
        pass
    
    
        
            
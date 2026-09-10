from asmbler import Tokenizer, TokenType, Parser

from asmbler.util.rigister import RegisterHelper
from asmbler.passes.codeGen import CodeGen

p = Parser("test.txt")
code: CodeGen = CodeGen()

t = Tokenizer("test.txt")

for i in p.parse():
    b: bytes = i.visit(code)
    ins: str = bin(int.from_bytes(b, byteorder='big'))
    ins = ins.removeprefix('0b')
    
    while len(ins) != 32:
        ins = "0" + ins
    
    print(ins)
    #print(ins[0:5])
    #print(ins[6:10])
    #print(ins[10:15])
    #print(ins[16:31])
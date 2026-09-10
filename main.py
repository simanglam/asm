from asmbler import Tokenizer, TokenType, Parser

from asmbler.util.rigister import RegisterHelper
from asmbler.passes.codeGen import CodeGen

p = Parser("test.txt")
code: CodeGen = CodeGen()

for i in p.parse():
    b: bytes = i.visit(code)
    print(bin(int.from_bytes(b, byteorder='big'))[2:7])
    print(bin(int.from_bytes(b, byteorder='big'))[8:12])
    print(bin(int.from_bytes(b, byteorder='big'))[13:17])
    print(bin(int.from_bytes(b, byteorder='big'))[18:33])
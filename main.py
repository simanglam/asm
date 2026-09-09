from asmbler import Tokenizer, TokenType, Parser

from asmbler.util.rigister import RegisterHelper

p = Parser("test.txt")


for i in p.parse():
    print(i)
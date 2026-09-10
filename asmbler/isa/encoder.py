
from ..util import FunctCode, Opcodes, RegisterEnum
from ..operands import Operand, Register, Immediate, Label

from . import FunctMapperTable, OpcodesMappingTable, RegisterMappingTable

class Encoder():
    def __init__(self):
        pass
    
    
    def emitI(self, opcodes: Opcodes, rd: Register, rs: Register, immediate: int) -> bytes:
        if (immediate.val >= 2 ** 16):
            print("Error to enocde")
        ins: int = 0
        
        ins |= OpcodesMappingTable[opcodes]
        ins <<= 5
        
        ins |= RegisterMappingTable[rs.register]
        ins <<= 5
        
        ins |= RegisterMappingTable[rd.register]
        ins <<= 16
        
        ins |= immediate.val
        
        return ins.to_bytes(4)
    
    def emitR(self, opcodes: Opcodes, funct: FunctCode, rd: Register, rs: Register, rt: Register) -> bytes:
        ins = 0
        
        ins |= OpcodesMappingTable[opcodes]
        ins <<= 5
        
        ins |= RegisterMappingTable[rs.register]
        ins <<= 5
        
        ins |= RegisterMappingTable[rt.register]
        ins <<= 5
                
        ins |= RegisterMappingTable[rd.register]
        ins <<= 10
    
        ins |= FunctMapperTable[funct]
        return bytes(ins)
        
    def emitJ(self, opcodes: Opcodes, immediate: Immediate) -> bytes:
        if (immediate.val >= 2 ** 26):
            print("Error to enocde")
        
        ins = 0
        ins |= OpcodesMappingTable[opcodes]
        ins <<= 26
                
        ins |= immediate.val
        return bytes(ins)
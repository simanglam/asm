
from dataclasses import dataclass

from .opcode import Opcodes
from .funct import FunctCode
from .format import Format

@dataclass
class InstructionDefination:
    opcode: int
    functCode: FunctCode
    format: Format

INSTRUCTION_DEFINITION_TABLE: dict[Opcodes, InstructionDefination] = {
    Opcodes.ADD: 
        InstructionDefination(0b0, 0b100000, Format.R),
    Opcodes.SUB: 
        InstructionDefination(0b0, 0b100010, Format.R),
    Opcodes.AND: 
        InstructionDefination(0b0, 0b100100, Format.R),
    Opcodes.OR: 
        InstructionDefination(0b0, 0b100101, Format.R),
    Opcodes.ADDI: 
        InstructionDefination(0b001000, 0b0, Format.I),
    Opcodes.LUI: 
        InstructionDefination(0b001111, 0b0, Format.I),
    Opcodes.MUL: 
        InstructionDefination(0b0, 0b011000, Format.R),
    Opcodes.DIV: 
        InstructionDefination(0b0, 0b011010, Format.R),
    Opcodes.REM: 
        InstructionDefination(0b0, 0b011011, Format.R),
        
    # Memory access
    Opcodes.LW: 
        InstructionDefination(0b100011, 0, Format.I),
    Opcodes.SW: 
        InstructionDefination(0b101011, 0, Format.I),
        
    # Branch Inst
    Opcodes.BEQ: 
        InstructionDefination(0b000100, 0, Format.I),
    Opcodes.J: 
        InstructionDefination(0b000010, 0, Format.J),
    Opcodes.JAL: 
        InstructionDefination(0b110000, 0, Format.J),
    Opcodes.JAL: 
        InstructionDefination(0b0, 0b001000, Format.R)
}
from ..util import Opcodes


OpcodesMappingTable: dict[Opcodes, int] = {
    Opcodes.ADD: 000000,
    Opcodes.SUB: 000000,
    Opcodes.AND: 000000,
    Opcodes.OR: 000000,
    Opcodes.ADDI: 0b001000,
    Opcodes.LUI: 0b001111,
    Opcodes.MUL: 000000,
    Opcodes.DIV: 000000,
    Opcodes.REM: 000000,
    
    # Memory code
    Opcodes.LW: 0b100011,
    Opcodes.SW: 0b100011,
    
    # Jump Code
    Opcodes.BEQ: 0b000100,
    Opcodes.J: 0b000010,
    Opcodes.JAL: 0b110000,
    
    Opcodes.JR: 000000,
}
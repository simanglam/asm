from ..util import FunctCode


FunctMapperTable: dict[FunctCode, int] = {
    FunctCode.ADD: 0b100000,
    FunctCode.SUB: 0b100010,
    FunctCode.AND: 0b100100,
    FunctCode.OR: 0b100101,
    FunctCode.MUL: 0b011000,
    FunctCode.DIV: 0b011010,
    FunctCode.REM: 0b011011,
           
    FunctCode.JR: 0b001000
}
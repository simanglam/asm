from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..asts import ASTNode, Instruction, LabelNode

from .instructionVisitor import InstructionVisitor

from ..isa import INSTRUCTION_DEFINITION_TABLE, Encoder
from ..util import Format


class CodeGen(InstructionVisitor):
    def __init__(self) -> None:
        self.encoder: Encoder = Encoder()
        pass

    def visitInstruction(self, abstractInstruction: Instruction) -> bytes:
        match INSTRUCTION_DEFINITION_TABLE[abstractInstruction.opcode].format:
            case Format.I:
                return self.encoder.emitI(
                    abstractInstruction.opcode,
                    abstractInstruction.oprands[0],
                    abstractInstruction.oprands[1],
                    abstractInstruction.oprands[2]
                )
            case Format.R:
                return self.encoder.emitR(
                    abstractInstruction.opcode,
                    abstractInstruction.funct,
                    abstractInstruction.oprands[0],
                    abstractInstruction.oprands[1],
                    abstractInstruction.oprands[2]
                    
                )
            case Format.J:
                return self.encoder.emitJ(
                    abstractInstruction.opcode,
                    abstractInstruction.oprands[0]
                )

    def visitLabel(self, abstractInstruction: LabelNode) -> bytes:
        return bytes(0)
        

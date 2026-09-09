from enum import Enum, auto

class RegisterEnum(Enum):
    r1 = auto()
    r2 = auto()
    r3 = auto()
    r4 = auto()
    r5 = auto()
    r6 = auto()
    r7 = auto()
    r8 = auto()
    r9 = auto()
    r10 = auto()
    r11 = auto()
    r12 = auto()
    r13 = auto()
    r14 = auto()
    r15 = auto()
    r16 = auto()
    r17 = auto()
    r18 = auto()
    r19 = auto()
    r20 = auto()
    r21 = auto()
    r22 = auto()
    r23 = auto()
    r24 = auto()
    r25 = auto()
    r26 = auto()
    r27 = auto()
    r28 = auto()
    r29 = auto()
    r30 = auto()
    r31 = auto()

    err = auto()

class RegisterHelper:
    
    @staticmethod
    def strToRigisterEnum(literal: str) -> RegisterEnum:
        """Helper function for 
        """
        try: 
            return RegisterEnum[literal]
        except: 
            return RegisterEnum.err
            
            
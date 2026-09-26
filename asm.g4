grammar asm;

options {
	language = Cpp;
}



program: (instruction | directive)+;

directive:
	PERIOD id = ID
	val = INTEGER?
	;

instruction:
	ID
	operands += opreand
	(COMMA operands += opreand)+
	;

opreand:
	ID
	| REGISTER
	| INTEGER
	;


// lexer

COMMA: ',';
SEMICOLON: ';';
COLON: ':';
PERIOD: '.';

LEFT_PAR: '(';
RIGHT_PAR: ')';

REGISTER: 'r' DIGIT+;

// Numbers

INTEGER: DEC_NUM | HEX_NUM;

fragment DEC_NUM: (DIGIT)+;
fragment HEX_NUM: '0x' (DIGIT | 'a' ..'f')+;
FLOAT_NUM: FLOAT_NUM1 | FLOAT_NUM2;

fragment FLOAT_NUM1: (DIGIT)+ '.' (DIGIT)*;
fragment FLOAT_NUM2: '.' (DIGIT)+;

/* Comments */
// COMMENT: SINGLELINE_COMMENT | MULTILINE_COMMENT {skip();};
SINGLELINE_COMMENT: '//' (.)*? '\n' -> skip;
MULTILINE_COMMENT: '/*' (.)*? '*/' -> skip;

STRING_LITERAL : '"' ( ESC | ~('"' | '\\' | '\r' | '\n') )* '"' ;

fragment ESC : '\\' ('"' | '\\' | '/' | 'b' | 'f' | 'n' | 'r' | 't') ;

ID: (LETTER | '_') (LETTER | DIGIT | '_')*;

fragment LETTER: 'a' ..'z' | 'A' ..'Z' | '_';
fragment DIGIT: '0' ..'9';

WS: (' ' | '\t' | '\r' | '\n')+ -> skip;
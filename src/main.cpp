#include <any>
#include <string>
#include <iostream>

#include "asmLexer.h"
#include "asmParser.h"
#include "CharStream.h"
#include "ANTLRInputStream.h"
#include "parser/ASTs/ASTBuilder.h"
#include "passes/ASTPrinter.h"
#include "passes/Codegen.h"
#include "ISA/EncoderImpl.h"

using namespace antlr4;
using namespace std;

int main() {
	
    string line;
	ifstream modelicaFile ("test.txt");

	if (modelicaFile.is_open()) {
		antlr4::ANTLRInputStream input(modelicaFile);
		asmLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		tokens.fill();

		ConsoleErrorListener e;

		asmParser parser(&tokens);
		parser.addErrorListener(&e);
		asmParser::ProgramContext* tree = parser.program();
		
		modelicaFile.close();
		
		ASTBuilder builder;
		ASTPrinter printer;
		Codegen codegen(new EncoderImpl());

		if (parser.getNumberOfSyntaxErrors() > 0) {
        	std::cerr << "Parsing failed.\n";
        	return 1;
    	}

		Program* p = std::any_cast<Program*>(builder.visitProgram(tree));
		printer.visitProgram(p);
		list<unsigned int>* l = any_cast<list<unsigned int>*>(codegen.visitProgram(p));
		
		for (int i : *l) {
			printf("0x%08x\n", i);
			cout << ((i & 0xFC000000) >> 26) << endl;
			cout << ((i & 0x03E00000) >> 21) << endl;
			cout << ((i & 0x001F0000) >> 16) << endl;
		}
	}
}
#include <string>
#include <iostream>

#include "asmLexer.h"
#include "asmParser.h"
#include "CharStream.h"
#include "ANTLRInputStream.h"

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
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}

		asmParser parser(&tokens);
		tree::ParseTree *tree = parser.program();

		std::cout << tree->toStringTree(&parser) << std::endl;
		modelicaFile.close();
	}
}
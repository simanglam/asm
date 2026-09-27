#include <list>

#include "parser/ASTs/Program.h"

using namespace std;

Program::Program(list<AST*> _body): body(_body) {}

std::any Program::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitProgram(this);
}
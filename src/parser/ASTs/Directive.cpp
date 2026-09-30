#include "parser/ASTs/Directive.h"

using namespace std;

Directive::Directive(string _text, int _val): text(_text), val(_val) {}

std::any Directive::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitDirective(this);
}

std::string Directive::getText() const {
    return text;
}

int Directive::getVal() const {
    return val;
}
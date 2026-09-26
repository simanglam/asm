#pragma once
#include <any>

template<class t>
class ASTVisitor;

class AST {
public:

    virtual std::any accept(ASTVisitor<std::any>& visitor) = 0;

    virtual ~AST() = default;
};
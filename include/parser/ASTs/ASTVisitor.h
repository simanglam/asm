#pragma once

template<class t>
class ASTVisitor {
public:
    virtual t visit() = 0;
};
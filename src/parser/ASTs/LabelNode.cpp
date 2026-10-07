#include <string>
#include "parser/ASTs/LabelNode.h"

using namespace std;


LabelNode::LabelNode(std::string _text): text(_text) {

}

std::any LabelNode::accept(ASTVisitor<std::any>& visitor) {
    return visitor.visitLabelNode(this);
}
    
std::string LabelNode::getText() {
    return text;
}
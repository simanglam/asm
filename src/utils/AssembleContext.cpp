#include "utils/AssembleContext.h"

AssembleContext* AssembleContext::hidden = nullptr;
AssembleContext::AssembleContext() {

}

AssembleContext* AssembleContext::getInstance() {
    if (hidden == nullptr)
        hidden = new AssembleContext();

    return hidden;
}


    
Bytes AssembleContext::getLabelAddress(std::string& labelText) {
    return labelMap[labelText];
}

void AssembleContext::setLabelAddress(std::string& labelText, Bytes labelAddrress) {
    labelMap[labelText] = labelAddrress;
}


std::list<Bytes*>* AssembleContext::encodeToByte() {
    
}
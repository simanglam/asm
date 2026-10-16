#pragma once

#include <unordered_map>
#include <string>
#include <list>

#include "utils/Bytes.h"

class AssembleContext {
    static AssembleContext* hidden;
    AssembleContext();

    std::unordered_map<std::string, Bytes> labelMap;

public:
    static AssembleContext* getInstance();

    Bytes getLabelAddress(std::string&);
    void setLabelAddress(std::string&, Bytes);

    std::list<Bytes*>* encodeToByte();
};
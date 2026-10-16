#include "utils/Bytes.h"

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <format>

using namespace std;

Bytes::Bytes(unsigned int _bytes, int size): _size(size) {
    if (_bytes > pow(2, size)) {
        
    }

    bytes = new unsigned char[size];

    for (int i = size - 1; i >= 0; i--) {
        bytes[i] = _bytes & 0xFF;
        _bytes >>= 8;
    }
}

Bytes::~Bytes() {
    delete bytes;
}

int Bytes::size() const {
    return this->_size;
}

unsigned char* Bytes::encodeToLittle() {
    unsigned char* returnBytes = new unsigned char[_size];

    for (int i = 0; i < _size; i++) {
        returnBytes[i] = bytes[_size - i - 1];
    }
    return returnBytes;
}

unsigned char* Bytes::encodeToBig() {
    unsigned char* returnBytes = new unsigned char[_size];

    memcpy(returnBytes, bytes, _size);
    return returnBytes;
}

std::ostream& operator<<(std::ostream& os, Bytes& bytes) {
    char buf[50];

    for (int i = 0; i < bytes.size(); i++) {
        sprintf(buf, "%02x", bytes.bytes[i]);
        os << buf;
    }
        
    
    return os;
}
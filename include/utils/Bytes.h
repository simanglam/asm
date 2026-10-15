#pragma once

class Bytes {
    unsigned char* bytes;
    int _size;

public:
    Bytes(unsigned int = 0, int = 1);
    ~Bytes();
    int size() const;

    unsigned char* encodeToLittle();
    unsigned char* encodeToBig();
};
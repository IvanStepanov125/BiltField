#pragma once
#include <iostream>
#include <stdint.h>
#include "BitField.h"

class DecNum{
public:
    uint16_t* _array;
    int _size = 40;

    DecNum();
    DecNum(const DecNum& tmp);
    DecNum(const BitField& tmp);
    void Print();
    DecNum& operator=(const int num);
    DecNum& operator=(const DecNum& tmp);
    DecNum operator+(const DecNum& num);
    uint16_t& operator[](int i)const{
        return _array[i];
    }
    ~DecNum(){
        delete [] _array;
    }
};
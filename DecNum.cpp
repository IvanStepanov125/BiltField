#include "DecNum.h"
#include <string>
#include <iostream>

DecNum::DecNum(){
    _size = 40;
    _array = new uint16_t[_size];
    for (int i =0; i < _size; i++){
        _array[i] = 0;
    }
}

DecNum::DecNum(const DecNum& tmp){
    _size = tmp._size;
    _array = new uint16_t[_size];
    for (int i =0; i < _size; i++){
        _array[i] = tmp._array[i];
    }
};

DecNum::DecNum(const BitField& tmp){
    DecNum res;
    DecNum prom_res;
    _size = 40;
    _array = new uint16_t[_size];
    for (size_t i = 0; i < tmp.GetLength(); i ++){
        if (tmp.IsTrue(i)){
            prom_res = 1;
            for (size_t j = 0; j < i; j++){
                prom_res = prom_res + prom_res;
            }
            res = res + prom_res; 
        }   
    }
    for (int i = 0; i < _size; i++){
        _array[i] = res[i];
    }
};

DecNum& DecNum::operator=(const int num){
    for (int i =0; i < _size; i++){
        _array[i] = 0;
    }
    std::string stroka = std::to_string(num);
    int len = stroka.length();
    for(int i = 0; i < len; i++){
        _array[_size - 1 - i] = stroka[len - 1 - i] - '0';
    }
    return *this;
};

DecNum& DecNum::operator=(const DecNum& tmp){
    for(int i = 0; i < _size; i++){
        _array[_size - 1 - i] = tmp[_size - 1 - i];
    }
    return *this;
};

DecNum DecNum::operator+(const DecNum& num){
    DecNum copy(*this);
    DecNum res;
    for (int i = 0; i < _size; i ++){
        if (copy[_size - 1 - i] + num[_size - 1 - i] > 9){
            res[_size - 2 - i] ++;
        }
        res[_size - 1 - i] = (copy[_size - 1 - i] + num[_size - 1 - i] + res[_size - 1 - i]) % 10;
    }
    return res;
};

void DecNum::Print(){
    DecNum res(*this);
    for (size_t i = 0; i < res._size; i ++){
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}
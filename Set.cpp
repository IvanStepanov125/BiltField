#include "Set.h"
#include "cmath"

Set::Set(size_t mp) : _bitField(mp){
    _maxPower = mp;
}

Set::Set(const Set& set) : _bitField(set._bitField), _maxPower(set._maxPower){
}

Set::Set(const BitField& bf)  : _bitField(bf), _maxPower(bf.GetLength()){
}

size_t Set::GetMaxPower()const {
    return _maxPower;
}

void Set::InsElem(uint64_t elem){ //Проверка нужна
    _bitField.SetBit(elem);
}

void Set::DelElem(uint64_t elem){ //Проверка нужна
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem) const{
    return _bitField.GetBit(elem);
}

std::vector<uint64_t> Set::GetPrimary(){
    Set tmp(*this);
    size_t n = GetMaxPower(), qn = static_cast<size_t> (sqrt (n)) + 1;
    
    for (size_t i = 2; i < qn; i ++){
        if (i != 0){
            for (size_t j = i + i; j < n; j += i){
                tmp._bitField.ClrBit(j);
                }
            }
    }
    std::vector<size_t> res;
    res.push_back(1);
    for (size_t i = 2; i < n; i++){
        if (tmp._bitField.GetBit(i)){
            res.push_back(i);
        }
    }
    return res;
}

bool Set::operator==(const Set& tmp) const{
    return (tmp._bitField == this->_bitField);
};
bool Set::operator!=(const Set& tmp) const{
    return !(tmp._bitField == this->_bitField);
};
Set& Set::operator=(const Set& tmp){
    _maxPower = tmp._maxPower;
    _bitField = tmp._bitField;
    return *this;
};
Set Set::operator+(const Set &tmp){
    BitField tmp1(this->_bitField | tmp._bitField);
    Set res(tmp1);
    return res;
}; //объединение двух множеств
Set Set::operator+(const uint64_t elem){
    Set res(*this);
    res.InsElem(elem);
    return res;
}; //добавление элемента
Set Set::operator-(const uint64_t elem){
    Set res(*this);
    res.DelElem(elem);
    return res;
}; //удаление элемента
Set Set::operator*(const Set& tmp){
    BitField tmp1(this->_bitField & tmp._bitField);
    Set res(tmp1);
    return res;
};

Set Set::operator~(){
    Set res(~(this->_bitField));
    return res;
};
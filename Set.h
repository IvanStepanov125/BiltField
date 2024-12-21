#pragma once
#include "BitField.h"
#include "vector"

class Set{
    private:
        BitField _bitField;
        size_t _maxPower;
    public:
        Set(size_t mp);
        Set(const Set& set);
        Set(const BitField& bf);
        operator BitField(){
          return _bitField;
        };

        size_t GetMaxPower() const;
        void InsElem(const uint64_t elem);
        void DelElem(const uint64_t elem);
        bool IsMember(const uint64_t elem) const;
        std::vector<uint64_t> GetPrimary();

        bool operator==(const Set& tmp) const;
        bool operator!=(const Set& tmp) const;
        Set& operator=(const Set& tmp);
        Set operator+(const Set &tmp); //объединение двух множеств
        Set operator+(const uint64_t elem); //добавление элемента
        Set operator-(const uint64_t elem); //удаление элемента
        Set operator*(const Set& tmp); //пересечене двух множеств
        Set operator~();//дополнение

        friend std::istream& operator>>(std::istream istr, Set& set);
        
        friend std::ostream& operator<<(std::ostream& os, const Set& set){
            for (int i = 0; i < set._maxPower; i++){
                if (set._bitField.GetBit(i) == 1){
                    std::cout<<i<<" ";
                }
            }
            std::cout<<"\n";
            return os;
        };

};
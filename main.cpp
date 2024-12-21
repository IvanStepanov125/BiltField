#include "BitField.h"
#include "Set.h"
#include "DecNum.h"


int main() {
    BitField a = BitField(129);
    a.SetBit(128);

    BitField b = BitField(129);
    b.SetBit(9);
    b.SetBit(6);
    b.SetBit(5);
    b.SetBit(1);
    b.SetBit(0);
    DecNum aD(a);
    DecNum bD(b);
    aD.Print();
    bD.Print();
    DecNum cA;
    cA = aD + bD;
    cA.Print();
}
//friend...bla-bla-bla
//int tmp = 0;
//os<<"("
// for(size_t i = 0; i < 128; i++){
// os<<Bitfield.IsTrue(i); //IsTrue - bool функция return Bitfield.GetBit(elem)
// tmp++;
//if(tmp == 15){
// os<<" "
// tmp = 0;
//}
//}
//os<<")";
//я бы отдельный класс заделал
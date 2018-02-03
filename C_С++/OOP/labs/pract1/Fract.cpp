#include <iostream>
#include "Fract.h"
#include <cmath>

using namespace std;
void Fract::toRight()
{
    int n = fabs(ch)<fabs(zn)?fabs(ch):fabs(zn);
    for (; n>1; n--)
        if (ch%n==0 && zn %n==0) break;
    ch/=n;
    zn/=n;
}

Fract::Fract(int cel, int ch, int zn)
{
    this->zn = zn;
    this->ch = cel*zn+ch;
    toRight();

}

void Fract:: setCh(int ch)
{
  int cel=ch/zn;
  this->ch=ch+zn*cel;
}
void Fract:: setZn(int zn){this->zn=zn;}
void Fract::setCel(int cel)
{
    ch+=(cel-ch/zn)*zn;
}

Fract Fract::sum(const Fract&b)const
{
    Fract tmp;
    tmp.ch=ch*b.zn+b.ch*zn;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::dif(const Fract&b)const
{
    Fract tmp;
    tmp.ch=ch*b.zn-b.ch*zn;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::mul(const Fract&b)const
{
    Fract tmp;
    tmp.ch=ch*b.ch;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::dev(const Fract&b)const
{
    Fract tmp;
    tmp.ch=ch*b.zn;
    tmp.zn=b.ch*zn;
    tmp.toRight();
    return tmp;
}


int Fract::more(const Fract &b)const {
    return ch/zn > b.ch/b.zn;
}

int Fract::less(const Fract &b)const {
    return ch/zn < b.ch/b.zn;
}

int Fract::equals(const Fract &b)const {
  return ch==b.ch && zn==b.zn;
}

void Fract::show()
{
    if(ch/zn) cout << ch/zn<<" ";
    if(ch%zn) cout << ch%zn<<"/"<<zn;
    if(ch/zn==0 && ch%zn ==0) cout << 0;
}








#include <iostream>
#include "Fract.h"
#include <cmath>

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
void Fract:: setZn(int zn)
{
    this->zn=zn;
}
void Fract::setCel(int cel)
{
    ch+=(cel-ch/zn)*zn;
}

Fract & Fract::operator-()
{
    ch*=(-1);
    return *this;
}


Fract Fract::operator+(const Fract&b)
{
    Fract tmp;
    tmp.ch=ch*b.zn+b.ch*zn;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::operator-(const Fract&b)
{
    Fract tmp;
    tmp.ch=ch*b.zn-b.ch*zn;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::operator*(const Fract&b)
{
    Fract tmp;
    tmp.ch=ch*b.ch;
    tmp.zn=b.zn*zn;
    tmp.toRight();
    return tmp;
}
Fract Fract::operator/(const Fract&b)
{
    Fract tmp;
    tmp.ch=ch*b.zn;
    tmp.zn=b.ch*zn;
    tmp.toRight();
    return tmp;
}

Fract Fract:: operator+(int num)
{
    Fract tmp;
    tmp.ch=ch+num*zn;
    tmp.zn=zn;
    tmp.toRight();
    return tmp;
}

Fract Fract::operator-(int num)
{
    Fract tmp;
    tmp.ch=ch-num*zn;
    tmp.zn=zn;
    tmp.toRight();
    return tmp;
}

Fract Fract::operator*(int num)
{
    Fract tmp;
    tmp.ch=ch*num;
    tmp.zn=zn;
    tmp.toRight();
    return tmp;
}

Fract Fract::operator/(int num)
{
    Fract tmp;
    tmp.ch=ch;
    tmp.zn=zn*num;
    tmp.toRight();
    return tmp;
}

Fract Fract::operator%(int num)
{
    Fract tmp;
    tmp.ch=ch%(num*zn);
    tmp.zn=zn;
    tmp.toRight();
    return tmp;
}

Fract &Fract::operator++()
{
    ch+=zn;
    return *this;
}

Fract Fract::operator++(int a)
{
    Fract tmp(*this);
    ch+=zn;
    return tmp;
}
Fract &Fract::operator--()
{
    ch-=zn;
    return *this;
}
Fract Fract::operator--(int a)
{
    Fract tmp(*this);
    ch-=zn;
    return tmp;
}

int Fract::operator >(const Fract &b)const
{
    return ch/zn > b.ch/b.zn;
}

int Fract::operator<(const Fract &b)const
{
    return ch/zn < b.ch/b.zn;
}

int Fract::operator >=(const Fract &b)const
{
    return ch/zn >= b.ch/b.zn;
}

int Fract::operator<=(const Fract &b)const
{
    return ch/zn <= b.ch/b.zn;
}


int Fract::operator==(const Fract &b)const
{
    return ch==b.ch && zn==b.zn;
}

void Fract::operator()()
{
    if(ch/zn) cout << ch/zn<<" ";
    if(ch%zn) cout << ch%zn<<"/"<<zn;
    if(ch/zn==0 && ch%zn ==0) cout << 0;
}

int Fract::operator[](int num)
{
       switch (num)
    {
    case 1 :
        getCel();
        break;
    case 2 :
        getCh();
        break;
    case 3 :
        getZn();
        break;
    default:
        return 0;
    }
}

Fract::operator double()
{
    return (double)ch/zn;
}


Fract operator +( int num,const Fract  &V )
{
    Fract tmp;
    tmp.ch=V.ch+V.zn*num;
    tmp.zn=V.zn;
    tmp.toRight();
    return tmp;
}
Fract operator -( int num,const Fract  &V )
{
    Fract tmp;
    tmp.ch=V.zn*num-V.ch;
    tmp.zn=V.zn;
    tmp.toRight();
    return tmp;
}

Fract operator *( int num,const Fract  &V )
{
    Fract tmp;
    tmp.ch=V.ch*num;
    tmp.zn=V.zn;
    tmp.toRight();
    return tmp;
}

Fract operator /( int num,const Fract  &V )
{
    Fract tmp;
    tmp.ch=V.ch;
    tmp.zn=V.zn*num;
    tmp.toRight();
    return tmp;
}


ostream & operator<<(ostream& to, const Fract& V)
{
    if(V.ch/V.zn) to << V.ch/V.zn<<" ";
    if(V.ch%V.zn) to << V.ch%V.zn<<"/"<<V.zn;
    if(V.ch/V.zn==0 && V.ch%V.zn ==0) to << 0;
    return to;
}

istream & operator >>(istream &in, Fract &V)
{
    int x,y,z;
    in>>x>>y>>z;
    V.setZn(z);
    V.setCh(y);
    V.setCel(x);
    return in;
}










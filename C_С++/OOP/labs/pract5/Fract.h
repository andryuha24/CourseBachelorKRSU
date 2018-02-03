#ifndef FRACT_H_INCLUDED
#define FRACT_H_INCLUDED
using namespace std;
class Fract
{
private:
    int ch, zn;
    void toRight();
public:
    Fract(){ch=1; zn=1;}
    Fract(int ch, int zn, int cel);
    ~Fract() {};

    int getCh(){return ch%zn;}
    int getZn(){return zn;}
    int getCel(){return (ch/zn);}
    void setCh(int);
    void setZn(int);
    void setCel(int);

    Fract&operator-();

    Fract  operator+(const Fract&);
    Fract operator-(const Fract&);
    Fract operator*(const Fract&);
    Fract operator/(const Fract&);

    Fract  operator+(int);
    Fract operator-(int);
    Fract operator*(int);
    Fract operator/(int);
    Fract operator%(int);

    Fract &operator ++();
    Fract operator ++( int);

    Fract &operator --();
    Fract operator --( int);

    int operator > (const Fract  &)const;
    int operator < (const Fract &)const;
    int operator >= (const Fract &)const;
    int operator <= (const Fract  &)const;
    int operator == (const Fract &)const;

    void operator()();
    int operator[](int);

    operator double();

    friend Fract operator +( int,const Fract  & );
    friend Fract operator - (int,const Fract  &);
    friend Fract operator *(int, const Fract  &);
    friend Fract operator /(int, const Fract &);

    friend istream & operator >>(istream &, Fract &);
    friend ostream & operator<<(ostream &, const Fract &);


    void show();
};


#endif // FRACT_H_INCLUDED

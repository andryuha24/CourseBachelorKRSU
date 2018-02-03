#ifndef FRACT_H_INCLUDED
#define FRACT_H_INCLUDED
class Fract
{
private:
    int ch, zn;
    void toRight();
public:
    Fract(){ch=1;zn=1;}
    Fract(int ch, int zn, int cel);
    ~Fract() {};

    int getCh(){return ch;}
    int getZn(){return zn;}
    int getCel(){return (ch/zn);}
    void setCh(int);
    void setZn(int);
    void setCel(int);

    Fract  sum(const Fract&)const;
    Fract dif(const Fract&)const;
    Fract mul(const Fract&)const;
    Fract dev(const Fract&)const;

    int more(const Fract  &)const;
    int less(const Fract &)const;
    int equals(const Fract &)const;

    void show();
};


#endif // FRACT_H_INCLUDED

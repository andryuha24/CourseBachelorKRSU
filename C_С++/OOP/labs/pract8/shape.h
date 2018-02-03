#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
using namespace std;
class Shape
{
protected:
    int color;
public:
    Shape(){color=14;}
    Shape(int color){this->color=color;}
    virtual ~Shape(){cout<<"I'm destructor of shape\n";}
    int getColor(){return color;}
    void setColor(int c){this->color=c;}
    virtual void show()=0;
    virtual void hide()=0;
    virtual void move(int dx, int dy)=0;
    virtual void moveTo(int x, int y)=0;
    virtual  show()=0;
};

class MCircle::public virtual Shape
{
protected:
    int x,y,r;
public:
    MCircle():Shape()
    {
        x=100;
        y=100;
        r= 20;
    }
    MCircle(int,x, int y, int R, int c):Shape(c)
    {
        this->x=x;
        this->y=y;
        this->r=r;
    }
    virtual ~MCircle(){cout <<"I'm destructor of Circle\n";}
    int getX(){return x;}
    int getY(){return y;}
    int getR(){return r;}
    void setX(int x){this->x=x;}
    void setY(int y){this->y=y;}
    void setR(int r){this->r=r;}
    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);
};

class Triangle:public Shape
{
protected:
    int x,y,l;
public:
    Triangle():Shape()
    {
        x=500;
        y=200;
        l=30;
    }
    Triangle(int x,int y, int l,int c):Shape()
    {
        this->x=x;
        this->y=y;
        this->l=l;
        color=c;
    }
    virtual ~Triangle(){cout<<"I'm destructor of triangle\n";}
    int getX();
    int getY();
    int getL();
    void setX(int);
    void setY(int);
    void setL(int);

    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);
};

class MRectangle:public virtual Shape
{
protected:
    int x,y,l1,l2;
public:
    MRectangle():Shape()
    {
        x=500;
        y=300;
        l1=50;
        l2=30;
    }
    MRectangle(int x,int y,int l1,int l2,int c):Shape()
    {
        color=c;
        this->x=x;
        this->y=y;
        this->l1=l1;
        this->l2=l2;
    }
    virtual ~MRectangle(){cout<<"I'm destructor rect"<<endl;}
    int getX();
    int getY();
    int getL1();
    int getL2();
    void setX(int);
    void setY(int);
    void setL1(int);
    void setL2(int);

    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);

};

class FRectangle:public MRectangle
{
protected:
    int fillcolor;
public:
    FRectangle():MRectangle()
    {
        fillcolor=3;
        x=500;
        y=400;
        l1=50;
        l2=30;
    }
    FRectangle(int x,int y, int l1,int l2,int c,int f_c):MRectangle()
    {
        color=c;
        fillcolor=f_c;
        this->x=x;
        this->y=y;
        this->l1=l1;
        this->l2=l2;

    }
    virtual ~FRectangle(){cout<<"I'm destructor of fill rectangle\n";}
    void setFillcolor(int);
    int getFillcolor();
    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);
};

class FCircle:public MCircle
{
protected:
    int fillcolor;
public:
    FCircle():MCircle()
    {
        fillcolor=1;
        x=500;
        y=500;
        r=50;
    }
    FCircle(int x,int y,int r,int c,int f_c):MCircle()
    {
        this->x=x;
        this->y=y;
        this->r=r;
        color=c;
        fillcolor=f_c;
    }
    virtual ~FCircle(){cout<<"I'm destructor of fill circle\n";}
    void setFillcolor(int);
    int getFillcolor();
    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);

};

class FReCircle: public MCircle,public FRectangle  //fill  Circle into Frectangle
{
public:
    using MCircle::x;
    using MCircle::y;
    using MCircle::r;
    using FRectangle::color;
    using FRectangle::fillcolor;
    FReCircle():MCircle(),FRectangle()
    {
        this->x=700;
        this->y=700;
        this->r=30;
        this->color=3;
        this->fillcolor=1;
    }
    FReCircle(int x,int y,int r,int c,int f_c):MCircle(),FRectangle()
    {
        this->x=x;
        this->y=y;
        this->r=r;
        color=c;
        fillcolor=f_c;
    }
    virtual  ~FReCircle(){cout<<"I'm destructor of ReC"<<endl;}

    virtual void show();
    virtual void hide();
    virtual void move(int dx,int dy);
    virtual void moveTo(int x,int y);
};

#endif // SHAPE_H_INCLUDED

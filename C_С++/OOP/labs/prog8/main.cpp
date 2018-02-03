#include <iostream>
#include <stdio.h>
#include "Graphics.h"
#include "shape.h"


int Shape::getColor(){return color;}
void Shape::setColor(int c){this->color=c;}

int MCircle::getX() {return x;}
int MCircle::getY() {return y;}
int MCircle::getR() {return r;}
void MCircle::setX(int x) {this->x=x;}
void MCircle::setY(int y) {this->y=y;}
void MCircle::setR(int r) {this->r=r;}
void MCircle::show(){ circle(x,y,r);}
void MCircle::hide()
{
    color=0;
    setcolor(color);
    circle(x,y,r);
}
void MCircle::move(int x,int y)
{
    this->x=x;
    this->y=y;
}
void MCircle::moveTo(int dx,int dy)
 {
    for(int i=1; i<100; i++) {
        delay(1);
        cleardevice();
        this->x+=dx;
        this->y+=dy;
        show();
        }
  }



int Triangle::getX(){return x;}
int Triangle::getY(){return y;}
int Triangle::getL(){return l;}
void Triangle::setX(int x){this->x=x;}
void Triangle::setY(int y){this->y=y;}
void Triangle::setL(int l){this->l=l;}
void Triangle::show()
{
    line(x,y,x-30,y-30);
    line(x,y,x+30,y-30);
    line(x-30,y-30,x+30,y-30);
}
void Triangle::hide()
{
    Shape::setColor(0);
    line(x,y,x-30,y-30);
    line(x,y,x+30,y-30);
    line(x-30,y-30,x+30,y-30);
}
void Triangle::move(int x,int y)
{
  this->x=x;
  this->y=y;
}
void Triangle::moveTo(int dx,int dy)
 {
    for(int i=1; i<100; i++) {
        delay(1);
        cleardevice();
        this->x+=dx;
        this->y+=dy;
        show();
        }
  }




int RectangleT::getX(){return x;}
int RectangleT::getY(){ return y;}
int RectangleT::getL1(){ return l1;}
int RectangleT::getL2(){ return l2;}
void RectangleT::setX(int x){this->x=x;}
void RectangleT::setY(int y){ this->y=y;}
void RectangleT::setL1(int l1){this->l1=l1;}
void RectangleT::setL2(int l2){this->l2=l2;}

void RectangleT::show(){rectangle(x,y,x+l1,y+l2);}
void RectangleT::hide()
{
    Shape::setColor(0);
    rectangle(x,y,x+l1,y+l2);
}
void RectangleT::move(int x,int y)
{
    this->x=x;
    this->y=y;
}
void RectangleT::moveTo(int dx,int dy)
{
     for(int i=1; i<100; i++) {
        delay(1);
        cleardevice();
        this->x+=dx;
        this->y+=dy;
        show();
        }
}


 void FRectangle::setFillcolor(int f_c)
 {
     this->fillcolor=f_c;
 }

int FRectangle::getFillcolor()
 {
     return fillcolor;
 }
void FRectangle::show()
{
    setbkcolor(0);
    setfillstyle(fillcolor,color);
    bar(x,y,x+l1,y+l2);
}
void FRectangle::hide()
{
    setfillstyle(0,0);
    bar(x,y,x+l1,y+l2);
    setfillstyle(0,0);
}

void FRectangle::move(int x,int y)
{
    this->x=x;
    this->y=y;
}
void FRectangle::moveTo(int dx,int dy)
{
     for(int i=1; i<100; i++)
    {
        setbkcolor(0);
        delay(1);
        cleardevice();
        this->x+=dx;
        this->y+=dy;
        show();
     }
}



void FCircle::setFillcolor(int c){fillcolor=c;}
int FCircle::getFillcolor(){return fillcolor;}
void FCircle::show()
{

    setfillstyle(fillcolor,color);
    fillellipse(x,y,r,r);

}
void FCircle::hide()
{
    setfillstyle(0,0);
    fillellipse(x,y,r,r);
}
void FCircle::move(int x,int y)
{
    this->x=x;
    this->y=y;
}
void FCircle::moveTo(int dx,int dy)
{
    for(int i=1; i<100; i++)
    {
      setbkcolor(0);
      delay(1);
      cleardevice();
      this->x+=dx;
      this->y+=dy;
      show();
    }
}

void FReCircle::show()
{
    setfillstyle(fillcolor,color);
    bar(x-r,y-r,x+r,y+r);
    setcolor(fillcolor);
    circle(x,y,r);
}
void FReCircle::hide()
{
    setfillstyle(0,0);
    bar(x-r,y-r,x+r,y+r);
    setcolor(0);
    circle(x,y,r);
}
void FReCircle::move(int x,int y)
{
    this->x=x;
    this->y=y;
}
void FReCircle::moveTo(int dx,int dy)
{
    for(int i=1; i<100; i++)
    {
      setbkcolor(0);
      delay(1);
      cleardevice();
      this->x+=dx;
      this->y+=dy;
      show();
    }
}

Shape* mult( int i)
{
 Shape *ps;

      if(i==0)   ps=new MCircle;
      if(i==1)   ps=new RectangleT;
      if(i==2)   ps=new Triangle;
      if(i==3)   ps=new FCircle;
      if(i==4)   ps=new FRectangle;
      if(i==5)   ps=new FReCircle;
      return ps;
}

void graph() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode);
    setbkcolor(0);
    }
int main()
{
    graph();

    //setcolor(3);
 //  MCircle a;
   /* a.show();
    a.move(800,800);
    a.show();
    a.moveTo(-1,-1);
*/
  //  Triangle b;
    /*b.show();
    b.move(900,900);
    b.show();
    b.moveTo(-1,-1);
*/
  //  RectangleT c;
 /*   c.show();
    c.move(500,500);
    c.show();
    c.moveTo(-1,-1);

*/
 //   FRectangle r;
    /*r.show();
    r.move(500,500);
    r.show();
    r.moveTo(-1,-1);
*/
 //   FCircle fc;
 /*   fc.show();
    fc.move(500,500);
    fc.show();
    fc.moveTo(-1,-1);
*/
   FReCircle fre;
  fre.show();
    fre.move(500,500);
    fre.show();
    fre.moveTo(-1,-1);


   /* const int N=6;
    Shape *ps[N];//={&a,&c,&r,&fc,&fre};

    for(int i=0;i<N;i++)
    {
     ps[i]=mult(i);
     ps[i]->show();// ps[i]->show();
    }
    for(int i=0;i<N;i++)
    {
     delete ps[i];
    }
*/
    Sleep(10000); //getch();
    closegraph();


    return 0;
}

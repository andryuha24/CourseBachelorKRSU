#include<stdio.h>
#include <Graphics.h>
#include <math.h>
#include "MCircle.h"
#include "MPixel.h"
#include <time.h>
#include <iostream>

using namespace std;

MCircle::MCircle()
{
    x=100;
    y=100;
    r=20;
    c=15;
}
MCircle::MCircle(int x, int y, int r, int c)
{
    this->x=x;
    this->y=y;
    this->r=r;
    this->c=c;
}

double MCircle::getSquare()
{
    return M_PI*(r^2);
}
double MCircle::getPer()
{
    return 2*M_PI*r;
}

void MCircle::move(int dx,int dy, int n)
{
    hide(n);
    x+=dx;
    y+=dy;
    show(n);
}

void MCircle::moveTo(int x,int y,int n)
{
    hide(n);
    this->x=x;
    this->y=y;
    show(n);
}

int MCircle::equals(const MCircle&b) const
{
    return (r==b.r);
}

void MCircle::show(int n)
{
    char m1[5];
    sprintf(m1, "%d", n);
    setcolor(c);
    outtextxy(x,y,m1);
    circle(x,y,r);
}
void MCircle::hide(int n)
{


    char m1[5];
    sprintf(m1, "%d", n);
    setcolor(0);

    outtextxy(x,y,m1);
    circle(x,y,r);
}


MPixel::MPixel()
{
    x=100;
    y=100;
    c=15;
}
MPixel::MPixel(int x,int y, int c)
{
    this->x=x;
    this->y=y;
    this->c=c;
}

int MPixel::equals(const MPixel&b) const
{
    return (c==b.c);
}

void MPixel::move(int dx,int dy)
{
    hide();
    x+=dx;
    y+=dy;
    show();
}
void MPixel::moveTo(int x,int y)
{
    hide();
    this->x=x;
    this->y=y;
    show();
}


void MPixel::show()
{
    putpixel(x,y,c);
}
void MPixel::hide()
{
    putpixel(x,y,0);
}



MCircle  *generator()
{
    int r=random(30)+20;
    int x=random(getmaxx())+r;
    int y=random(110);
    return new MCircle(x,y,r,random(15)+2);
}/*
void showM()
{
    MCircle *pc;
    while(!kbhit())
    {
        pc=generator();
        while(pc->getY()<getmaxy())
        {
            pc->move(0,pc->getY(),int n);
            delay(100);
        }
        pc->hide(n);
        delete pc;
    }
}*/
void shapes()
{
    MCircle a[4];
    MPixel b[1000];
    int ma[4][2]= {5, 5, 5, 5, 5, 5, 5, 5};
    for(int i=0; i<1000; i++)
    {
        b[i].setX(random(getmaxx()));
        b[i].setY(random(getmaxy()));
        b[i].setC(random(15)+1);
    }
    for(int i=0; i<4; i++)
    {
        a[i].setX(random(getmaxx()-110)+50);
        a[i].setY(random(getmaxy()-110)-50);
        a[i].setR(random(30)+10);
        a[i].setC(random(15)+2);
        if(a[i].getR()>15)cout<<i+1;


    }
    while(!kbhit())
    {
        for(int i=0; i<4; i++)
        {
            if(a[i].getX()+a[i].getR()>=getmaxx())ma[i][0]=-5;
            if(a[i].getX()-a[i].getR()<=0)ma[i][0]=5;
            if(a[i].getY()+a[i].getR()>=getmaxy())ma[i][1]=-5;
            if(a[i].getY()-a[i].getR()<=0)ma[i][1]=5;
            a[i].move(ma[i][0],ma[i][1],i);
            //a[i].show(i+1);
        }
        delay(50);
        for(int i=0; i<1000; i++)
        {
            if(b[i].getY()>getmaxy()) b[i].move(0,-getmaxy());
            b[i].show();
            b[i].move(0,1);
        }
    }
}

int main()
{

    srand(time(NULL));
    int i;
    cout<<"Vibirite operaciyu: ";
    cin >> i;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    setbkcolor(0);
    switch(i)
    {
    case 1:
        shapes();
        break;
    case 2:
//        showM();
        break;
    default:
        return 0;
    }
    closegraph();
   //
    return 0;
}

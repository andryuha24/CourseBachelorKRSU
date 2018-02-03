#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Graphics.h"/*
#include "shape.h"


void MCircle::show()
{
    setcolor(color);
    circle(x,y,r);
}
void MCircle::hide()
{
    setcolor(0);
    circle(x,y,r);
}
void MCircle::move(int dx,int dy)
{
    hide();
    x+=dx;
    y+=dy;
    show();
}
void MCircle::moveTo(int x,int y)
{
    hide();
    this->x=x;
    this->y=y;
    show();
}
*/


int main()
{
     srand(time(NULL));
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
  /*  MCircle a[4];
      int ma[4][2]= {5, 5, 5, 5, 5, 5, 5, 5};
     for(int i=0; i<4; i++)
    {
        a[i].setX(random(getmaxx()-110)+50);
        a[i].setY(random(getmaxy()-110)-50);
        a[i].setR(random(30)+10);
        a[i].setC(random(15)+2);
       // if(a[i].getR()>15)cout<<i+1;
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

    }
 closegraph();*/
    return 0;
}

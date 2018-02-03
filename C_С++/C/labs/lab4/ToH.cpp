#include "Graphics.h"
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define Y 20
int n,delaytime;
int manual=0,flag=1;
int diskisin[5];
int position[5];
int countdisk[3];
void box(int x1,int y1,int x2,int y2,int work)
{
  int c2=RED,c1=BLUE;
  if(work)
  {
   if(flag==0)
    flag=1;
   else
    flag=0;
   switch(flag)
   {
    case 0: c1=RED;
     c2=BLUE;
     break;
    case 1: c2=RED;
     c1=BLUE;
     break;
   }
  }
  bar(x1,y1,x2,y2);
  setcolor(c1);
  line(x1,y1,x2,y1);
  line(x1,y1,x1,y2);
  setcolor(c2);
  line(x1,y2,x2,y2);
  line(x2,y1+1,x2,y2);
}
void create(int n)
{
 int i,x,y,size;
 for(i=0;i<n;i++)
 {
  //creates box
  x=5+(diskisin[i]*215)+((4-i)*20);
  y=150+position[i]*30;
  size=40+i*40;
  setfillstyle(SOLID_FILL,10+i);
  box(x,y,x+size,y+Y,1);
 }
}
void movedisk(int Disk,int from, int to)
{
 int x,y,size=Disk*40,tx,ty;
 //box cordinates...
 x=5+(diskisin[Disk-1]*215)+((5-Disk)*20);
 y=150+position[Disk-1]*30;
 do
 {
  setfillstyle(SOLID_FILL,BLACK);
  bar(x,y,x+size,y+Y);
  y-=30;
  setfillstyle(SOLID_FILL,9+Disk);
  box(x,y,x+size,y+Y,1);
  if(manual) getch();
  else delay(delaytime);
 }while(y>60);
 tx=5+(to*215)+((5-Disk)*20);
 do
 {
  setfillstyle(SOLID_FILL,BLACK);
  bar(x,y,x+size,y+Y);
  if(tx<x) x-=43; else x+=43;
  setfillstyle(SOLID_FILL,9+Disk);
  box(x,y,x+size,y+Y,1);
  if(manual) getch();
  else delay(delaytime);
 }while(x!=tx);
 position[Disk-1]=n-1-countdisk[to];
 countdisk[to]++;
 countdisk[from]--;
 diskisin[Disk-1]=to;
 ty=150+position[Disk-1]*30;
 do
 {
  setfillstyle(SOLID_FILL,BLACK);
  bar(x,y,x+size,y+Y);
  y+=30;
  setfillstyle(SOLID_FILL,9+Disk);
  box(x,y,x+size,y+Y,1);
  if(manual) getch();
  else delay(delaytime);
 }while(y<ty);
}
void tower(int n,int from,int to,int aux)
{
 //recursive call function...(logic for TOWER OF HANOi)
 if(n==1)
 {
  movedisk(1,from,to);
  return;
 }
 tower(n-1,from,aux,to);
 movedisk(n,from,to);
 tower(n-1,aux,to,from);
}
int main()
{
 int i;
 int gd=DETECT,gm;
 do
 {
  printf("\nEnter no. of disks :-limit(1-5):-  ");
  scanf("%d",&n);
 }while((n<1)&&(n>5));
 delaytime=(6-n)*100;
initgraph(&gd,&gm,"c:\\turboC3\\bgi");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
 setbkcolor(RED);
 cleardevice();
 setfillstyle(SOLID_FILL,GREEN);
 box(150,13,490,33,0);
 box(160,324,480,346,0);
 setcolor(WHITE);
 outtextxy(180,10,"T O W E R  O F  H A N O I");
 setcolor(RED);
 outtextxy(190,321,"Developed by - Gaurav Singhal");
 setcolor(DARKGRAY);
 outtextxy(181,11,"T O W E R  O F  H A N O I");
 setcolor(BLUE);
 outtextxy(191,322,"Developed by - Gaurav Singhal");
 countdisk[0]=n;
 countdisk[1]=0;
 countdisk[2]=0;
 for(i=0;i<n;i++)
 {
  position[i]=i;
  diskisin[i]=0;
 }
 create(n);
 tower(n,0,2,1);
 getch();
 closegraph();
 return 0;
}

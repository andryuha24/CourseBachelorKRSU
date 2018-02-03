// Лаба №4
// вариант №7
#include<conio.h>
#include<stdio.h>
#include <Graphics.h>
#include <locale.h>
int main()
{
  setlocale(LC_CTYPE,"Russian");
  float x,y;
  int i,j;

  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode);
  setbkcolor(3);

  cleardevice();//очистка активной страницы




  setcolor(1);
  for(i=0;i<=30;i++)line(100,100+i*10,500,100+i*10);
  for(i=0;i<=40;i++)line(100+i*10,100,100+i*10,400);

  setcolor(10);
  //Основные оси.
  line(100,250,500,250);
  line(300,100,300,400);


  //Стрелки
  line(500,250,480,245);
  line(500,250,480,255);

    line(300,100,295,120);
    line(300,100,305,120);

  arc(200,150,0,90,100);
  rectangle(200,250,301,350);
  setcolor(14);
  outtextxy(190,240,"-1");
  outtextxy(400,240,"1");
  outtextxy(300,350,"-1");
  outtextxy(300,140,"1");
  printf("Input X and Y: ");
  scanf("%f %f",&x,&y);

  setlinestyle(0, 1, 1);
  setcolor(11);
  circle(300+x*100,250-y*100,2);
    if(((x<=1.0)&&(x>=0.0)&&(sqrt(x*x+y*y)<=1.0) && (y>=0.0)) || ((x>=-1.0)&&(x<=0.0)&&(y<=0.0)&&(y>=-1.0)))
    {
        printf("Point (%.5f,%.5f) in zone.",x,y);

    }else
    {
        printf("Point (%.5f,%.5f) out of zone.",x,y);
    }

  getch();
  return 0;
}

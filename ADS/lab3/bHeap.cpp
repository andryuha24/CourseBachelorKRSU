#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Graphics.h"
#include <string.h>
using namespace std;
int n, tmp2=0;
const int maxV = 15;
int *heap = new int[maxV];
int heapSize = 0;
int parent = 0, child = 0;

void colors(int a,int b,int c,int d);
void graph();
void interfeis(int *);
void ChangeColors(int *);

void outxy(int x, int y, int var)
{
   char buf[10];
   snprintf(buf, sizeof(buf), "%d", var);
   outtextxy(x, y, buf);
}


void MoveDown(int index)
{
int k, tmp;
    k = index * 2;

child = 0, parent = 0;


if (k <heapSize)
    {
if ((k + 1 <heapSize) && (heap[k] < heap[k + 1])) k++;
if (heap[index] < heap[k])
        {

child = k;
parent = index;


tmp = heap[index];
heap[index] = heap[k];
heap[k] = tmp;
MoveDown(k);
        }
    }
}

/* Извлекает max эл-т из кучи */
int GetMax(void)
{
int value;
value = heap[1];
heap[1] = heap[heapSize];
heap[heapSize] = 0;
heapSize--;
MoveDown(1);
return value;
}


void MoveUp1(int index)
{
int k, tmp;
    k = index / 2;

child = 0, parent = 0;


if (index > 1)
    {
if (heap[index] > heap[k])
        {

child = index;
parent = k;
tmp = heap[index];
heap[index] = heap[k];
heap[k] = tmp;
MoveUp1(k);
        }
    }
}

/* Поднимает эл-т вверх, пока он больше предка */
void MoveUp(int index)
{
int k, tmp;
    k = index / 2;

child = 0, parent = 0;


if (index > 1)
    {
if (heap[index] > heap[k])
        {

child = index;
parent = k;
tmp = heap[index];
heap[index] = heap[k];
heap[k] = tmp;
ChangeColors(heap);
Sleep(1000);

MoveUp(k);
        }
    }
}


void ChangeColors(int *mas)
{
 cleardevice();
 graph();
  //первый уровень
int poly1[8]={700,20,
530,250,
870,250,
700,20
};
//второй уровень
int poly2[10]={700,250,
870,250,
980,400,
700,400,
700,250
};
int poly3[10]={700,250,
530,250,
420,400,
700,400,
700,250
};
//третий
int poly4[10]={420,400,
560,400,
505,550,
310,550,
420,400
};
int poly5[10]={560,400,
700,400,
700,550,
505,550,
560,400,
};
int poly6[10]={700,400,
840,400,
895,550,
700,550,
700,400
};
int poly7[10]={840,400,
980,400,
1090,550,
895,550,
840,400
};
//четвертый
int poly8[10]={310,550,
405,550,
330,700,
200,700,
310,550
};
int poly9[10]={405,550,
505,550,
450,700,
330,700,
405,550
};
int poly10[10]={505,550,
605,550,
580,700,
450,700,
505,550
};
int poly11[10]={605,550,
700,550,
700,700,
580,700,
605,550
};
int poly12[10]={700,550,
805,550,
830,700,
700,700,
700,550
};
int poly13[10]={805,550,
895,550,
950,700,
830,700,
805,550
};
int poly14[10]={895,550,
1005,550,
1080,700,
950,700,
895,550
};
int poly15[10]={1005,550,
1090,550,
1200,700,
1080,700,
1005,550
};
 int i = 0;
 settextstyle(GOTHIC_FONT, HORIZ_DIR, 10);
 setcolor(15);
 if(mas[1]){
     if ((i==parent-1 || i==child-1) && tmp2==1){ setfillstyle(1,8);fillpoly(3,poly1);}
else  {setfillstyle(1,1); fillpoly(3,poly1);}
    outxy(700-10, 110, mas[1]);
 }

  for(int i=1; i < n; i++)
    {
      switch(i)
      {
        case 1: if(mas[2]) {if ((i==parent-1 || i==child-1) && tmp2==1){ setfillstyle(1,8);fillpoly(4,poly3);}
else  {setfillstyle(1,3);fillpoly(4,poly3);}outxy(700-100, 260, mas[2]);}break;
        case 2: if(mas[3]){if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly2);}
else  {setfillstyle(1,3);fillpoly(4,poly2);}outxy(700+100, 260, mas[3]);}break;
        case 3: if(mas[4]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly4);}
else  {setfillstyle(1,4);fillpoly(4,poly4);}outxy(700-250, 420, mas[4]);break;
        case 4: if(mas[5]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly5);}
else  {setfillstyle(1,4);fillpoly(4,poly5);}outxy(700-100, 420, mas[5]);}break;
        case 5: if(mas[6]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly6);}
else  {setfillstyle(1,4);fillpoly(4,poly6);}outxy(700+80, 420, mas[6]);}break;
        case 6: if(mas[7]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly7);}
else  {setfillstyle(1,4);fillpoly(4,poly7);}outxy(700+250, 420,mas[7]);}break;
        case 7: if(mas[8]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly8);}
else  {setfillstyle(1,7);fillpoly(4,poly8);}outxy(700-390, 570, mas[8]);}break;
        case 8: if(mas[9]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly9);}
else  {setfillstyle(1,7);fillpoly(4,poly9);}outxy(700-290, 570, mas[9]);}break;
        case 9:if(mas[10]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly10);}
else  {setfillstyle(1,7);fillpoly(4,poly10);}outxy(700-180, 570, mas[10]);}break;
        case 10:if(mas[11]) {if ((i==parent-1 || i==child-1) && tmp2==1){ setfillstyle(1,8);fillpoly(4,poly11);}
else  {setfillstyle(1,7);fillpoly(4,poly11);}outxy(700-70, 570, mas[11]);}break;
        case 11:if(mas[12]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly12);}
else  {setfillstyle(1,7);fillpoly(4,poly12);}outxy(700+50, 570, mas[12]);}break;
        case 12:if(mas[13]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly13);}
else  {setfillstyle(1,7);fillpoly(4,poly13);}outxy(700+150, 570, mas[13]);}break;
        case 13:if(mas[14]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly14);}
else  {setfillstyle(1,7);fillpoly(4,poly14);}outxy(700+260, 570, mas[14]);}break;
        case 14:if(mas[15]) {if ((i==parent-1 || i==child-1) && tmp2==1){setfillstyle(1,8);fillpoly(4,poly15);}
else  {setfillstyle(1,7);fillpoly(4,poly15);}outxy(700+370, 570, mas[15]);}break;
      }
    }
}
}

/* Добавляет эл-т в кучу */
void HeapAdd(int x)
{
if (heapSize<maxV)
    {
heapSize++;
heap[heapSize] = x;
interfeis(heap);
getch();
        tmp2=1;
MoveUp(heapSize);
    }
}



void HeapAdd1(int x)
{
if (heapSize<maxV)
    {
heapSize++;
heap[heapSize] = x;

MoveUp1(heapSize);
    }
}

/* Заполняет кучу по максимуму (до размеров массива) */
void fillHeap(void)
{
srand((unsigned int)time(NULL));
for (int i = 0; i< n; i++)
    {
HeapAdd1( rand()%100+1);
    }
}


void graph()
{
int gdriver = DETECT, gmode;

int i;
initgraph(&gdriver, &gmode);
setbkcolor(0);
cleardevice();
setcolor(15);
    setlinestyle(1,0,3);
    settextstyle(2,0,0);
    //Главный треугольник
    line(700,20,200,700);
    line(200,700,1200,700);
    line(700,20,1200,700);
    //разделение
    for(int i=0;i<3;i++)
        line(530-i*110,250+i*150,870+i*110,250+i*150);//Горизонтально
    //Вертикально
    line(700,250,700,700);
    line(560,400,450,700);
    line(840,400,950,700);
    for(int i=0; i<4;i++)
        line(405+200*i,550,330+(250*i),700);
    colors(1,3,4,7);

}

void interfeis(int *mas)
{
 //cleardevice();
 graph();
 settextstyle(GOTHIC_FONT, HORIZ_DIR, 10);
  setcolor(15);
  if(mas[1]){outxy(700-10, 110, mas[1]);}
  for(int i=1; i < n; i++)
    {
      switch(i)
      {
        case 1: if(mas[2])outxy(700-100, 260, mas[2]);break;
        case 2: if(mas[3])outxy(700+100, 260, mas[3]);break;
        case 3: if(mas[4])outxy(700-250, 420, mas[4]);break;
        case 4: if(mas[5])outxy(700-100, 420, mas[5]);break;
        case 5: if(mas[6])outxy(700+80, 420, mas[6]);break;
        case 6: if(mas[7])outxy(700+250, 420,mas[7]);break;
        case 7: if(mas[8])outxy(700-390, 570, mas[8]);break;
        case 8: if(mas[9])outxy(700-290, 570, mas[9]);break;
        case 9:if(mas[10])outxy(700-180, 570, mas[10]);break;
        case 10:if(mas[11])outxy(700-70, 570, mas[11]);break;
        case 11:if(mas[12])outxy(700+50, 570, mas[12]);break;
        case 12:if(mas[13])outxy(700+150, 570, mas[13]);break;
        case 13:if(mas[14])outxy(700+260, 570, mas[14]);break;
        case 14:if(mas[15])outxy(700+370, 570, mas[15]);break;
      }
    }



}

void colors(int a,int b,int c,int d)
{
    //первый уровень
int poly1[8]={700,20,
530,250,
870,250,
700,20
};
//второй уровень
int poly2[10]={700,250,
870,250,
980,400,
700,400,
700,250
};
int poly3[10]={700,250,
530,250,
420,400,
700,400,
700,250
};
//третий
int poly4[10]={420,400,
560,400,
505,550,
310,550,
420,400
};
int poly5[10]={560,400,
700,400,
700,550,
505,550,
560,400,
};
int poly6[10]={700,400,
840,400,
895,550,
700,550,
700,400
};
int poly7[10]={840,400,
980,400,
1090,550,
895,550,
840,400
};
//четвертый
int poly8[10]={310,550,
405,550,
330,700,
200,700,
310,550
};
int poly9[10]={405,550,
505,550,
450,700,
330,700,
405,550
};
int poly10[10]={505,550,
605,550,
580,700,
450,700,
505,550
};
int poly11[10]={605,550,
700,550,
700,700,
580,700,
605,550
};
int poly12[10]={700,550,
805,550,
830,700,
700,700,
700,550
};
int poly13[10]={805,550,
895,550,
950,700,
830,700,
805,550
};
int poly14[10]={895,550,
1005,550,
1080,700,
950,700,
895,550
};
int poly15[10]={1005,550,
1090,550,
1200,700,
1080,700,
1005,550
};

//первый уровень
setfillstyle(1, a);
fillpoly(3, poly1);
//второй уровень
setfillstyle(1, b);
fillpoly(4, poly2);
fillpoly(4, poly3);

//третий уровень
setfillstyle(1, c);
fillpoly(4, poly4);
fillpoly(4, poly5);
fillpoly(4, poly6);
fillpoly(4, poly7);

//четвертый уровень
setfillstyle(1, d);
fillpoly(4, poly8);
fillpoly(4, poly9);
fillpoly(4, poly10);
fillpoly(4, poly11);
fillpoly(4, poly12);
fillpoly(4, poly13);
fillpoly(4, poly14);
fillpoly(4, poly15);
}





int main()
{
 int tmp;
 graph();

cout<<"Input the size of heap: ";
cin>>n;


fillHeap();
interfeis(heap);


cout<<"Press any key\nto delete the max"<<endl;

getch();
GetMax();
interfeis(heap);
cout<<"input new element: ";
cin>>tmp;

HeapAdd(tmp);

cout<<"element "<<tmp<<" is added"<<endl<<"to heap."<<endl;

interfeis(heap);


getch();
delete heap;
return 0;

}

#include "Graphics.h"
#include <stdio.H>
#define YSize 30

int n,DELAY;
int IsManual=0,flag=1;
int DiskIsIn[7];
int PosInPeg[7];
int DiskCount[3];
char m1[5],m2[5],m3[5],m4[5];

void DrawHanoi(int n)
{

	int i,x,y,size;
	for(i=0;i<n;i++){
		x=50+(DiskIsIn[i]*215)+((5-i)*15);
		y=150+PosInPeg[i]*30;
		size=30+i*30;

		setcolor(RED);
		switch(n)
		{
            case 3:
                {
                    line(140,90,140,240);
                    line(355,90,355,240);
                    line(570,90,570,240); break;
                }
         case 4:
                {
                    line(140,90,140,272);
                    line(355,90,355,272);
                    line(570,90,570,272); break;
                }
                 case 5:
                {
                    line(140,90,140,302);
                    line(355,90,355,302);
                    line(570,90,570,302); break;
                }
                 case 6:
                {
                    line(140,90,140,332);
                    line(355,90,355,332);
                    line(570,90,570,332); break;
                }
                 case 7:
                {
                    line(140,90,140,362);
                    line(355,90,355,362);
                    line(570,90,570,362); break;
                }

		}

		setcolor(BLACK);
		setfillstyle(SOLID_FILL,9+i);
		bar(x,y,x+size,y+YSize);
	}
}

int i = 1;
void MoveDisk(int Disk,int from, int to)
{

	int x,y,size=Disk*30,tx,ty;
	x=50+(DiskIsIn[Disk-1]*215)+((6-Disk)*15);
	y=150+PosInPeg[Disk-1]*30;
	setcolor(GREEN);
	    sprintf(m1, "%d", Disk);
        sprintf(m2, "%d", from+1);
        sprintf(m3,"%d", to+1);
        sprintf(m4,"%d)", i);
		if(0<n && n <5)
    {
        outtextxy(720,50+35*i,m4);
        outtextxy(780,50 +35*i,m1);
        outtextxy(800,50 +35*i,"disk");
        outtextxy(860,50 +35*i,m2);
        outtextxy(880,50 +35*i,"->");
        outtextxy(900,50 +35*i,m3);
    }
	setcolor(BLACK);
	do{
        setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		y-=30;
        setcolor(RED);
        switch(n)
		{
          case 3:{
                  line(140,90,140,240);
                  line(355,90,355,240);
                  line(570,90,570,240); break;
                }
         case 4:{
                 line(140,90,140,272);
                 line(355,90,355,272);
                 line(570,90,570,272); break;
                }
        case 5:{
                line(140,90,140,302);
                line(355,90,355,302);
                line(570,90,570,302); break;
               }
        case 6:{
                line(140,90,140,332);
                line(355,90,355,332);
                line(570,90,570,332); break;
               }
        case 7:{
                line(140,90,140,362);
                line(355,90,355,362);
                line(570,90,570,362); break;
               }
		}
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,8+Disk);
		bar(x,y,x+size,y+YSize);
		if(IsManual) getch();
		else delay(DELAY);
	  }while(y>100);

	tx=50+(to*215)+((6-Disk)*15);
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
        setcolor(RED);
        switch(n)
		{
          case 3:{
                  line(140,90,140,240);
                  line(355,90,355,240);
                  line(570,90,570,240); break;
                }
         case 4:{
                 line(140,90,140,272);
                 line(355,90,355,272);
                 line(570,90,570,272); break;
                }
        case 5:{
                line(140,90,140,302);
                line(355,90,355,302);
                line(570,90,570,302); break;
               }
        case 6:{
                line(140,90,140,332);
                line(355,90,355,332);
                line(570,90,570,332); break;
               }
        case 7:{
                line(140,90,140,362);
                line(355,90,355,362);
                line(570,90,570,362); break;
               }
		}
		setcolor(BLACK);
		if(tx>x) x+=43; else x-=43;

		setfillstyle(SOLID_FILL,8+Disk);
	    bar(x,y,x+size,y+YSize);
		if(IsManual) getch();
		else delay(DELAY);
	}while(x!=tx);

	PosInPeg[Disk-1]=n-1-DiskCount[to];
	DiskCount[to]++;
	DiskCount[from]--;
	DiskIsIn[Disk-1]=to;
	ty=150+PosInPeg[Disk-1]*30;
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		y+=30;
        setcolor(RED);
        switch(n)
		{
         case 3:{
                 line(140,90,140,240);
                 line(355,90,355,240);
                 line(570,90,570,240); break;
                }
         case 4:{
                 line(140,90,140,272);
                 line(355,90,355,272);
                 line(570,90,570,272); break;
                }
        case 5:{
                line(140,90,140,302);
                line(355,90,355,302);
                line(570,90,570,302); break;
               }
        case 6:{
                line(140,90,140,332);
                line(355,90,355,332);
                line(570,90,570,332); break;
               }
        case 7:{
                line(140,90,140,362);
                line(355,90,355,362);
                line(570,90,570,362); break;
               }
		}
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,8+Disk);
	    bar(x,y,x+size,y+YSize);
		if(IsManual) getch();
		else delay(DELAY);
	}while(y<ty);
    i++;
}


void Towers(int n,int from,int to,int aux)
{

    if(n==1)
    {
        MoveDisk(1,from,to);
        return;
    }

    Towers(n-1,from,aux,to);
    MoveDisk(n,from,to);
    Towers(n-1,aux,to,from);
}

int main()
{
	int i;
	DELAY=50; //задержка
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode);

    do{
        printf("Hanoiskie Bashni. Vvedite kolichestvo diskov (1-7): ");
        scanf("%d",&n);
        switch(n)
        {
          case 1: printf("Maksimalnoe kolichestvo hodov 1"); break;
          case 2: printf("Maksimalnoe kolichestvo hodov 3"); break;
          case 3: printf("Maksimalnoe kolichestvo hodov 7"); break;
          case 4: printf("Maksimalnoe kolichestvo hodov 15"); break;
          case 5: printf("Maksimalnoe kolichestvo hodov 31"); break;
          case 6: printf("Maksimalnoe kolichestvo hodov 63"); break;
          case 7: printf("Maksimalnoe kolichestvo hodov 127"); break;
        }
      }while((n<1)&&(n>7));

     settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
     setbkcolor(BLACK);
     cleardevice();
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(2,2,3);

     DiskCount[0]=n;
     DiskCount[1]=0;
     DiskCount[2]=0;

     for(i=0;i<n;i++){PosInPeg[i]=i; DiskIsIn[i]=0;}

     DrawHanoi(n);
     getch();
     Towers(n,0,2,1);

     closegraph();
     return 0;
}

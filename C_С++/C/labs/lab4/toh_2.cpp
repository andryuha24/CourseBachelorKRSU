#include "Graphics.h"
#include <stdio.H>
#include <conio.H>
#include <dos.h>

#define YSize 20

int n,DELAY;
int IsManual=1,flag=1;

int DiskIsIn[10];
int PosInPeg[10];
int DiskCount[3];

void SetMode()
{	int gdriver = VGA, gmode=VGAMED;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
}
/*
void Box(int x1,int y1,int x2,int y2,int doit=1){
		int c2=WHITE,c1=DARKGRAY;
		if(doit){
			if(flag==0) flag=1;
			else flag=0;
			switch(flag){
				case 0:{ c1=WHITE; c2=DARKGRAY; break; }
				case 1:{ c2=WHITE; c1=DARKGRAY; break; }
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
*/
void DrawHanoi(int n){
	int i,x,y,size;
	for(i=0;i<n;i++){
		x=40+(DiskIsIn[i]*215)+((4-i)*20);
		y=150+PosInPeg[i]*30;
		size=40+i*40;
		setfillstyle(SOLID_FILL,10+i);
		bar(x,y,x+size,y+YSize);
	}
}

void MoveDisk(int Disk,int from, int to){
	int x,y,size=Disk*40,tx,ty;

	x=5+(DiskIsIn[Disk-1]*215)+((5-Disk)*20);
	y=150+PosInPeg[Disk-1]*30;
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		y-=30;
		setfillstyle(SOLID_FILL,9+Disk);
		bar(x,y,x+size,y+YSize);
		if(IsManual) getch();
		else delay(DELAY);
	}while(y>60);

	tx=5+(to*215)+((5-Disk)*20);
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		if(tx<x) x-=43; else x+=43;
		setfillstyle(SOLID_FILL,9+Disk);
		bar(x,y,x+size,y+YSize);
		/*if(IsManual) getch();
		else delay(DELAY);*/
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
		setfillstyle(SOLID_FILL,9+Disk);
		bar(x,y,x+size,y+YSize);
		if(IsManual) getch();
		else delay(DELAY);
	}while(y<ty);
}

void Towers(int n,int from,int to,int aux){
	if(n==1){
		MoveDisk(1,from,to);
		return;
	}
	if(kbhit()) return;
	Towers(n-1,from,aux,to);
	if(kbhit()) return;
	MoveDisk(n,from,to);
	Towers(n-1,aux,to,from);
}

int main(){
	int i;

	do{	printf("\nEnter no. of disks (1-5): ");
		scanf("%d",&n);
	}while((n<1)&&(n>10));
	DELAY=100;

	SetMode();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setbkcolor(LIGHTGRAY);
	cleardevice();
	setfillstyle(SOLID_FILL,LIGHTGRAY);
//	bar(150,13,490,33,0);
	//bar(160,324,480,346,0);
	setcolor(WHITE);
	outtextxy(180,10,"T o w e r s   o f    H a n o i");
	outtextxy(205,321,"Press any key to S T O P");
	setcolor(DARKGRAY);
	outtextxy(181,11,"T o w e r s   o f    H a n o i");
	outtextxy(206,322,"Press any key to S T O P");

	DiskCount[0]=n;
	DiskCount[1]=0;
	DiskCount[2]=0;
	for(i=0;i<n;i++){	PosInPeg[i]=i; DiskIsIn[i]=0; }

	DrawHanoi(n);
	Towers(n,0,2,1);
	getch();
	closegraph();
	return 0;
}

#include "Graphics.h"
#include <stdio.H>
#define YSize 25

int n,DELAY;
int IsManual=1,flag=1;
int DiskIsIn[6];
int PosInPeg[6];
int DiskCount[3];//С
char m1[5],m2[5],m3[5];
	int i = 1;

void DrawHanoi(int n){
	int i,x,y,size;
	for(i=0;i<n;i++){
		x=50+(DiskIsIn[i]*210)+((4-i)*20);
		y=150+PosInPeg[i]*30;
		size=35+i*35;

		setcolor(5);
	    line(145,50,145,270);
	     line(360,50,360,270);
        line(575,50,575,270);
		setcolor(LIGHTGRAY);

		setfillstyle(SOLID_FILL,9+i);
		bar(x,y,x+size,y+YSize);

	}
}


void MoveDisk(int Disk,int from, int to){
	int x,y,size=Disk*35,tx,ty;

	x=50+(DiskIsIn[Disk-1]*215)+((5-Disk)*20);
	y=150+PosInPeg[Disk-1]*30;

        setcolor(RED);
        sprintf(m1, "%d", Disk);
        sprintf(m2, "%d", from);
        sprintf(m3,"%d", to);
        outtextxy(20,300+10*i,"Snimaem");
        outtextxy(130,300 +10*i,m1);
        outtextxy(150,300 +10*i,"-i disk s ");
        outtextxy(245,300 +10*i,m2);
        outtextxy(265,300 +10*i,"-go sterjnya i odevaem ego na ");
        outtextxy(565,300 +10*i,m3);
        outtextxy(585,300 +10*i,"-i sterjen");
		setcolor(LIGHTGRAY);

	do{

        setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x,y,x+size,y+YSize);
		y-=30;

		setfillstyle(SOLID_FILL,8+Disk);
		bar(x,y,x+size,y+YSize);

			setcolor(5);
	    line(145,50,145,270);
	     line(360,50,360,270);
	     line(575,50,575,270);
		setcolor(LIGHTGRAY);

		if(IsManual) getch();
		else delay(DELAY);
	}while(y>60);


	tx=50+(to*215)+((5-Disk)*20);

	do{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x,y,x+size,y+YSize);

		if(tx<x) x-=43;
		else x+=43;

		setfillstyle(SOLID_FILL,8+Disk);
	    bar(x,y,x+size,y+YSize);

	    		setcolor(5);
	    line(145,50,145,270);
	     line(360,50,360,270);
  line(575,50,575,270);
		setcolor(LIGHTGRAY);

		if(IsManual) getch();
		else delay(DELAY);
	}while(x!=tx);


	PosInPeg[Disk-1]=n-1-DiskCount[to];
	DiskCount[to]++;
	DiskCount[from]--;
	DiskIsIn[Disk-1]=to;
	ty=150+PosInPeg[Disk-1]*30;

	do{
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x,y,x+size,y+YSize);
		y+=30;

		setfillstyle(SOLID_FILL,8+Disk);
	    bar(x,y,x+size,y+YSize);

	    	setcolor(5);
	    line(145,50,145,270);
	     line(360,50,360,270);
	 line(575,50,575,270);
		setcolor(LIGHTGRAY);

		if(IsManual) getch();
		else delay(DELAY);
	}while(y<ty);

    i++;

}

//Ханойские
void Towers(int n,int from,int to,int aux){
	if(n==1){
		MoveDisk(1,from,to);
		return;
	}
	Towers(n-1,from,aux,to);
	MoveDisk(n,from,to);
	Towers(n-1,aux,to,from);
}

int main(){

	DELAY=100; //задержка
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);

    printf("\nEnter no. of disks (1-5): ");
    scanf("%d",&n);
    if(n < 7)
    {
        cleardevice();
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        floodfill(2,2,3);

        DiskCount[0]=n;
        DiskCount[1]=0;
        DiskCount[2]=0;
        for(i=0;i<n;i++){PosInPeg[i]=i; DiskIsIn[i]=0; }
        DrawHanoi(n);
        Towers(n,0,2,1);
    }
    else printf("oblom");

	getch();
	closegraph();
	return 0;
}

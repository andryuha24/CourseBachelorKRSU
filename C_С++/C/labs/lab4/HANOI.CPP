#include<stdio.h>
#include<string.h>

#include<conio.h>
#include "Graphics.h"
#include<dos.h>
#include<stdlib.h>


void draw_poles(void);
void draw_disks(int n);
void redraw_disks(int i, int k, int n);
void pushi(int i);
void pushk(int i);
void pushj(int i);
int popi(void);
int popj(void);
int popk(void);

void HANOI(int n, int i, int j, int k);

int gd,gm,topi,topj,topk;
int diskxr[10];
int sti[10],stj[10],stk[10];
main()
{
int n,i;
char ch;
gd = DETECT, gm;
initgraph(&gd, &gm, "");
cleardevice();

draw_poles();
while(1)
	{

	for(i=0;i<10;++i)
		{
		sti[i]=0;stj[i]=0;stk[i]=0;
		}
	topi=-1;topj=-1;topk=-1;
	setcolor(8);
	settextstyle(0,0,1);
	outtextxy(80,360,"Enter the number of disk (<1-9>:0 to exit): ");

	ch = getch();
	n=ch-48;
	if(n==0)
		break;
	for(i=n;i>=1;--i)
		pushi(i);
	cleardevice();
	draw_poles();
	draw_disks(n);

	HANOI(n,1,2,3);
	getch();
	}
}

void HANOI(int n, int i, int j, int k)
{
int td;
if(n==1)
	{
	if(i==1)
		td=popi();
	else if(i==2)
		td=popj();
	else if(i==3)
		td=popk();
	if(k==1)
		pushi(td);
	else if(k==2)
		pushj(td);
	else if(k==3)
		pushk(td);


	redraw_disks(i,k,n);

	}
else    {
	HANOI(n-1,i,k,j);

	if(i==1)
		td=popi();
	else if(i==2)
		td=popj();
	else if(i==3)
		td=popk();
	if(k==1)
		pushi(td);
	else if(k==2)
		pushj(td);
	else if(k==3)
		pushk(td);

	redraw_disks(i,k,n);

	HANOI(n-1,j,i,k);
	}

}
void draw_poles(void)
{
setcolor(6);
rectangle(100,50,110,220);
setfillstyle(SOLID_FILL,6);
floodfill(105,60,6);

rectangle(250,50,260,220);
setfillstyle(SOLID_FILL,6);
floodfill(255,60,6);

rectangle(400,50,410,220);
setfillstyle(SOLID_FILL,6);
floodfill(405,60,6);

setcolor(8);
rectangle(50,220,160,250);
setfillstyle(SOLID_FILL,8);
floodfill(55,240,8);

rectangle(200,220,310,250);
setfillstyle(SOLID_FILL,8);
floodfill(205,240,8);

rectangle(350,220,460,250);
setfillstyle(SOLID_FILL,8);
floodfill(355,240,8);

setcolor(0);
settextstyle(0,0,1);
outtextxy(85,230,"Pole 1");
outtextxy(235,230,"Pole 2");
outtextxy(385,230,"Pole 3");

setcolor(2);
settextstyle(1,0,2);
outtextxy(80,400,"Demonstration of Tower of Hanoi");
}


void draw_disks(int n)
{
int i,k,y;
for(i=n,k=0;i>0;--i,k++)
	{
	setcolor(i);
	setfillstyle(SOLID_FILL,i);
	y=220-(n-i+1)*6-6*k;
	fillellipse(105,y,i*10,6);
	diskxr[i-1]=i*10;
	}
delay(1000);
}

void redraw_disks(int i, int k, int n)
{
int x,y,a;
char str[10],temp[10];

cleardevice();
draw_poles();



if(k==1)
	{
	y=220-(topi+1)*6;
	x=105;
	}

else if(k==2)
	{
	y=220-(topj+1)*6;
	x=255;
	}

else if(k==3)
	{
	y=220-(topk+1)*6;
	x=405;
	}

for(a=0;a<=topi;++a)
	{
	setcolor(sti[a]);
	setfillstyle(SOLID_FILL,sti[a]);

	y=220-(a+1)*6-6*a;
	fillellipse(105,y,sti[a]*10,6);
	}
for(a=0;a<=topj;++a)
	{
	setcolor(stj[a]);
	setfillstyle(SOLID_FILL,stj[a]);

	y=220-(a+1)*6-6*a;
	fillellipse(255,y,stj[a]*10,6);
	}
for(a=0;a<=topk;++a)
	{
	setcolor(stk[a]);
	setfillstyle(SOLID_FILL,stk[a]);

	y=220-(a+1)*6-6*a;
	fillellipse(405,y,stk[a]*10,6);
	}

setcolor(14);
rectangle(50,300,460,340);
setfillstyle(SOLID_FILL,7);
floodfill(60,310,14);

setcolor(1);
itoa(i,temp,10);
strcpy(str,temp);
strcat(str," -> ");
itoa(k,temp,10);
strcat(str,temp);
settextstyle(1,0,1);
outtextxy(220,308,str);


delay(1000);
}
void pushi(int i)
{
++topi;
sti[topi]=i;
}
void pushj(int i)
{
topj++;
stj[topj]=i;
}
void pushk(int i)
{
topk++;
stk[topk]=i;

}

int popi(void)
{
int t;
t= sti[topi];
sti[topi]=0;
--topi;
return t;
}
int popj(void)
{
int t;
t= stj[topj];
stj[topj]=0;
--topj;
return t;
}
int popk(void)
{
int t;
t= stk[topk];
stk[topk]=0;
--topk;
return t;
}

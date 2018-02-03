#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "drob.h"
using namespace std;

void toWrong(Drob &d)
{
  d.chis+=d.cel*d.znam;
  d.cel = 0;
}

Drob socr(Drob &d)
{
  int n = abs(d.chis)<=abs(d.znam)?abs(d.chis):abs(d.znam);
  for(;n>1;n--)

    if(d.chis%n == 0 && d.znam % n == 0)
    {
      d.chis/=n;
      d.znam/=n;
    }
    return d;

}

Drob sum(Drob &d1, Drob &d2)
{
  toWrong(d1);
  toWrong(d2);
  Drob tmp;
  tmp.cel = 0;
  tmp.chis = d1.chis*d2.znam+d2.chis*d1.znam;
  tmp.znam=d1.znam*d2.znam;

  return socr(tmp);

}

Drob razn(Drob &d1, Drob &d2)
{
  toWrong(d1);
  toWrong(d2);
  Drob tmp;
  tmp.cel = 0;
  tmp.chis = d1.chis*d2.znam-d2.chis*d1.znam;
  tmp.znam=d1.znam*d2.znam;

  return socr(tmp);

}

Drob mul(Drob &d1, Drob &d2)
{
  toWrong(d1);
  toWrong(d2);
  Drob tmp;
  tmp.cel = 0;
  tmp.chis = d1.chis*d2.chis;
  tmp.znam=d1.znam*d2.znam;

  return socr(tmp);

}
Drob del(Drob &d1, Drob &d2)
{
  toWrong(d1);
  toWrong(d2);
  Drob tmp;
  tmp.cel = 0;
  tmp.chis = d1.chis*d2.znam;
  tmp.znam=d1.znam*d2.chis;

  return socr(tmp);

}

void toRight(Drob &d)
{
  d.cel = d.chis/d.znam;
  d.chis -= d.cel*d.znam;
}


void show(Drob d)
{
  toRight(d);
  if(d.cel==0)
    printf("%d / %d",d.chis, d.znam);
  else
    printf("%d %d / %d\n",d.cel, d.chis,d.znam);

}




int main()
{
    Drob a, b, c;
    int i;
   printf("                        y \n");
   printf(" Vviedte drob v vvide X -\n");
   printf("                        z\n");
   printf("1. ");
   scanf("%d %d %d",&a.cel,&a.chis,&a.znam);
   printf("2. ");
   scanf("%d %d %d",&b.cel,&b.chis,&b.znam);
   printf("Viberite operaciyu :\n");
    printf("    1.Summa drobei.\n");
    printf("    2.Raznost drobei.\n");
    printf("    3.Proizvedenie drobei.\n");
    printf("    4.delenie drobei.\n");

   scanf("%d",&i);
   switch(i)
   {
         case 1: c = sum(a,b); break;
         case 2: c = razn(a,b); break;
         case 3: c = del(a,b); break;
         case 4: c = mul(a,b); break;
         default: return 0;
   }
   show (c);


    return 0;
}

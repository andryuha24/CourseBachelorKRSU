#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "MDate.h"
using namespace std;

int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
const char* mon[]={" January ", " February ", " March ", " April' ", " May ", " June ", " July ", " August ", " September ", " October " ," November "," December "};

long MDate::to_LongDate(int y, int m, int d)
{
    fullDate=d;
    for(int i=0; i<m-1; i++)
    {
        fullDate+=months[i];
        if((y%4==0&&(y%100!=0||y%400==0))&&i==1)fullDate++;
    }
    for(int i = 1800; i<y; i++)
    {
        if(i%4==0 && (i%100!=0 || i%400==0)) fullDate+=366;
        else fullDate+=365;

    }
    return fullDate;
}

void MDate::from_LongDate(int& y, int& m, int& d)
{
    int dd=0,mm=0,yy=1800;
    for(int i=0; i<fullDate; i++)
    {
        dd++;
        if(dd>months[mm])
        {
            if((yy%4==0&&(yy%100!=0||yy%400==0))&&mm==1)
            {
                if(dd>29)
                {
                    dd=1;
                    mm++;
                }
            }
            else
            {
                dd=1;
                mm++;
            }
            if(mm>11)
            {
                mm=0;
                yy++;
            }
        }
    }
    d=dd;
    m=mm+1;
    y=yy;
    return;
}


MDate::MDate()
{
    time_t t;
    tm *t_m;
    time(&t);
    t_m=localtime(&t);
    fullDate=to_LongDate(t_m->tm_year+1900,t_m->tm_mon+1,t_m->tm_mday);
}
MDate::MDate(int y, int m, int d)
{
    fullDate=to_LongDate(y,m,d);
}

int MDate::getYear()
{
    int y,m,d;
    from_LongDate(y,m,d);
    return y;
}

int MDate::getMonth()
{
    int y,m,d;
    from_LongDate(y,m,d);
    return m;
}

int MDate::getDay()
{
    int y,m,d;
    from_LongDate(y,m,d);
    return d;
}

void MDate::setYear(int newY)
{
    int y,m,d;
    from_LongDate(y,m,d);
    fullDate=to_LongDate(newY,m,d);
    return;
}

void MDate::setMonth(int newM)
{
    int y,m,d;
    from_LongDate(y,m,d);
    fullDate=to_LongDate(y,newM,d);
    return;
}

void MDate::setDay(int newD)
{
    int y,m,d;
    from_LongDate(y,m,d);
    fullDate=to_LongDate(y,m,newD);
    return;
}

long MDate::diffDate( const MDate & MD, int num)
{
    int y,m,d, r;
    MDate tmp;
    if(fullDate>MD.fullDate)
        tmp.fullDate=fullDate-MD.fullDate;
    else
        tmp.fullDate=MD.fullDate-fullDate;
    tmp.from_LongDate(y,m,d);
    //днях
    if(num==1)
       r = tmp.fullDate;
    if(num==2)
        r = (y-1800)*12+m;
    if(num==3)
        r = y-1800;

    return r;
}

int MDate::equals(const MDate &b)
{
    if (fullDate == b.fullDate) return 1;
    else return 0;
}

int MDate::more(const MDate &b)
{
    if (fullDate > b.fullDate) return 1;
    else return 0;
}

int MDate::less(const MDate &b)
{
    if (fullDate < b.fullDate) return 1;
    else return 0;
}


void MDate::showDate(int type)
{
    int y,m,d;
    from_LongDate(y,m,d);
    if(type==1)
         printf("%02d.%02d.%02d",d,m,y);
    if(type==2)
    {
        switch(m)
        {
        case 1:cout<<d<<mon[0]<<y; break;
        case 2:cout<<d<<mon[1]<<y; break;
        case 3:cout<<d<<mon[2]<<y; break;
        case 4:cout<<d<<mon[3]<<y; break;
        case 5:cout<<d<<mon[4]<<y; break;
        case 6:cout<<d<<mon[5]<<y; break;
        case 7:cout<<d<<mon[6]<<y; break;
        case 8:cout<<d<<mon[7]<<y; break;
        case 9:cout<<d<<mon[8]<<y; break;
        case 10:cout<<d<<mon[9]<<y; break;
        case 11:cout<<d<<mon[10]<<y;break;
        case 12:cout<<d<<mon[11]<<y;break;
        }
    }

}



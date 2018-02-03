#include <iostream>
#include <stdio.h>
#include <time.h>
#include "MTime.h"
using namespace std;


void MTime::fromLong(int &h,int &m,int &s)
{
    h=int(long(fullTime/3600l));
    m=int(long((fullTime%3600l)/60l));
    s=int(fullTime%60l);
}
long MTime::toLong(int h, int m, int s)
{
    return h*3600l+m*60l+s;
}

MTime::MTime()
{
    time_t t;
    tm *t_m;
    time(&t);
    t_m=localtime(&t);
    fullTime=toLong(t_m->tm_hour,t_m->tm_min,t_m->tm_sec);

}
MTime::MTime(int h, int m, int s)
{
    fullTime=toLong(h,m,s);
}
int MTime::getSec()
{
    int h,m,s;
    fromLong(h,m,s);
    return s;
}
int MTime::getMin()
{
    int h,m,s;
    fromLong(h,m,s);
    return m;
}
int MTime::getHour()
{
    int h,m,s;
    fromLong(h,m,s);
    return h;
}
void MTime::setSec(int newS)
{
    int h,m,s;
    fromLong(h,m,s);
    fullTime=toLong(h,m,newS);
    return;
}
void MTime::setMin(int newM)
{
    int h,m,s;
    fromLong(h,m,s);
    fullTime=toLong(h,newM,s);
    return;
}
void MTime::setHour(int newH)
{
    int h,m,s;
    fromLong(h,m,s);
    fullTime=toLong(newH,m,s);
    return;
}

MTime MTime::diffTime(const MTime&b)
{
    MTime tmp;
    if(fullTime>b.fullTime)
       tmp.fullTime=fullTime-b.fullTime;
    else
        tmp.fullTime=b.fullTime-fullTime;
    return tmp;
}

int MTime::equals(const MTime &b)
{
    if (fullTime == b.fullTime) return 1;
    else return 0;
}

int MTime::more(const MTime &b)
 {
   if (fullTime > b.fullTime) return 1;
    else return 0;
}

int MTime::less(const MTime &b)
 {
  if (fullTime < b.fullTime) return 1;
    else return 0;
}

void MTime::showTime()
{
    int h,m,s;
    fromLong(h,m,s);
    printf("%02d:%02d:%02d",h,m,s);
}

MTime& MTime::inkr()
{
    ++fullTime%=86400;
}

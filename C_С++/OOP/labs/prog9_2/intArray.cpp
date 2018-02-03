#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <stdexcept>
#include "intArray.h"
using namespace std;

int intArray::count=0;
intArray::intArray()
{
    count++;
    p=NULL;
    n=0;
    error=1;

}
intArray::intArray(int n1)
{
    count++;
    n=n1;
    if(n1>10){throw Size();}
    else{
    p=new int[n];
    if(p==NULL) {error=1;throw(error);}
    else error=0;
    }
}
intArray::intArray(const intArray &a)
{
    count++;
    n=a.n;
    p=new int[n];
    if(p==NULL)  {error=1;throw(error);}
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    //cout<<"\nI am copyconstructor\n";

}

intArray::~intArray()
{
    count--;
    delete []p;
}
int  intArray::getElem(int i)
{
    if(i<=n)
    {
        error=0;
        return *(p+i);
    }
    else
    {
         {error=2;throw(error);}
        return NULL;
    }
}


int   intArray::getN()
{
    return n;
}

int    intArray::getMin()
{
    int min=p[0];
    for(int i=0; i<n; i++)
        if(p[i]<min) min=p[i];
    return min;
}


int  intArray::getMax()
{
    int max=p[0];
    for(int i=0; i<n; i++)
        if(p[i]>max) max=p[i];
    return max;

}
float intArray::getAverage()
{
    float aver=0;
    for(int i=0; i<n; i++)
        aver+=p[i];
    aver/=n;
    return aver;
}
int    intArray::getMediana()
{
    int tmp=n/2;
    return p[tmp];

}
int    intArray::getError()
{
    return error;
}

double intArray::getDis()
{
    double dis=0;
    float aver=0;
    aver=getAverage();
    for(int i=0; i<n; i++)
        dis+=(p[i]-aver)*(p[i]-aver)/n;
    return dis;

}
double intArray::getRMS()
{
    double RMS=0;
    RMS=sqrt(getDis());
    return RMS;
}

int intArray::getCount()
{
    return count;
}

void intArray::fill()
{
    for(int i=0; i<n; i++) p[i]= rand()%100+1;

}
void intArray::sort()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(p[i]>p[j]) swap(p[i],p[j]);

}


intArray intArray::operator +(const intArray & a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new int[n];
        tmp.n=n;
        if(tmp.p==NULL) {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]+a.p[i];


        }
    }
    else
    {
        tmp.p=new int[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]+a.p[i];
        }


        return tmp;



    }
}

intArray intArray::operator -(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new int[n];
        tmp.n=n;

        if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]-a.p[i];


        }
    }
    else
    {
        tmp.p=new int[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]-a.p[i];
        }


        return tmp;



    }
}
intArray intArray::operator *(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new int[n];
        tmp.n=n;

       if(tmp.p==NULL) {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]*a.p[i];


        }
    }
    else
    {
        tmp.p=new int[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]*a.p[i];
        }


        return tmp;

    }
}
intArray intArray::operator /(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new int[n];
        tmp.n=n;
        if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]/a.p[i];


        }
    }
    else
    {
        tmp.p=new int[a.n];
        tmp.n=a.n;

          if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]/a.p[i];
        }

        return tmp;
    }
}

intArray intArray::operator +(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new int[n];

     if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]+a;
    }
    return tmp;
}

intArray intArray::operator -(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new int[n];

     if(tmp.p==NULL) {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]-a;
    }
    return tmp;
}
intArray intArray::operator *(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new int[n];

      if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]*a;
    }
    return tmp;
}
intArray intArray::operator /(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new int[n];

    if(tmp.p==NULL)  {tmp.error=1;throw(tmp.error);}
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]/a;
    }
    return tmp;
}

intArray &intArray::operator ++()
{
    for(int i=0; i<n; i++)
        p[i]+=1;

    return *this;
}

intArray intArray::operator ++(int)
{
    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]+=1;
    return tmp;
}

intArray &intArray::operator --()
{
    for(int i=0; i<n; i++)
        p[i]-=1;
    return *this;
}

intArray intArray::operator --(int)
{

    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]-=1;
    return tmp;
}

int &intArray::operator [](int a)
{

       int tmp=getElem(a);
       return tmp;
}
void intArray::operator()()
{
    for(int i=0; i<n; i++)
        cout<<p[i]<<endl;

}

void *intArray::operator new(size_t size)
{
    printf("operator new %d\n",size);
    void *m=malloc(size);
    if(!m) puts("out of memory!\n");
    return m;
}

void intArray::operator delete (void* addr)
{
    puts("operator delete");
    free(addr);
}

intArray &intArray::operator =(const intArray &a)// m=a=a
{
  if(this!=&a)
  {
    delete []p;
    n=a.n;
    p=new int[n];
    if(p==NULL) {error=1;throw(error);}
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    }
  return *this;
}

int intArray::operator ==(const intArray &a)
{
    int k=0;
    if(n==a.n)
    {
        for(int i=0; i<n; i++)
        {
            if(p[i]==a.p[i])k++;
        }
    }
    if((k==n))return 1;
    else return 0;
}

int intArray::operator !=(const intArray &a)
{
    intArray tmp1(*this),tmp2(a);
    if((tmp1==tmp2)==0)return 1;
    else return 0;
}

int intArray::operator >(const intArray &a)
{
    return n>a.n;
}
int intArray::operator >=(const intArray &a)
{
    return n>=a.n;
}
int intArray::operator <(const intArray &a)
{
    return n<a.n;
}
int intArray::operator <=(const intArray &a)
{
    return n<=a.n;
}
intArray operator +(int a, const intArray &b)
{
    intArray tmp(b);
    for(int i=0; i<b.n; i++)
        tmp.p[i]=a+b.p[i];
    return tmp;

}
intArray operator -(int a, const intArray &b)
{
    intArray tmp(b);
    for(int i=0; i<b.n; i++)
        tmp.p[i]=b.p[i]-a;
    return tmp;
}
intArray operator *(int a, const intArray &b)
{
    intArray tmp(b);
    for(int i=0; i<b.n; i++)
        tmp.p[i]=a*b.p[i];
    return tmp;
}
intArray operator /(int a, const intArray &b)
{
    intArray tmp(b);
    for(int i=0; i<b.n; i++)
        tmp.p[i]=b.p[i]/a;
    return tmp;
}


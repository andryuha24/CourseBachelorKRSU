#ifndef INTARRAY_H_INCLUDED
#define INTARRAY_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
using namespace std;
template <class Type> class intArray
{
private:
    Type * p;
    int n;
    int error;//error=0 если ошибок нет
    //error=1 если p=NULL
    //error=2 если индекс выходит за границу
    static int count;//количество созданных объектов
    //в конструкторе наращивать, в деструкторе уменьшать

public:
    intArray();
    intArray(int n);
    intArray(const intArray &);
    ~intArray();

    Type   getElem(int i);
    int    getN();
    Type    getMin();
    Type    getMax();
    float getAverage();
    Type    getMediana();
    int    getError();
    double getDis();
    double getRMS();
    static int getCount();
    void fill();
    void sort();

    intArray operator +(const intArray &);
    intArray operator -(const intArray &);
    intArray operator *(const intArray &);
    intArray operator /(const intArray &);

    intArray operator +(int a);
    intArray operator -(int a);
    intArray operator *(int a);
    intArray operator /(int a);

    intArray &operator ++();
    intArray operator ++(int);

    intArray &operator --();
    intArray operator --(int);

    int& operator [](int a);
    void operator ()();

    void *operator new(size_t size);
    void operator delete (void* addr);

    intArray &operator =(const intArray &);
    int operator ==(const intArray &);
    int operator !=(const intArray &);
    int operator >(const intArray &);
    int operator >=(const intArray &);
    int operator <(const intArray &);
    int operator <=(const intArray &);
/*
    friend intArray operator +(int a, const intArray &);
    friend intArray operator -(int a, const intArray &);
    friend intArray operator *(int a, const intArray &);
    friend intArray operator /(int a, const intArray &);*/
};
//специализированый класс
template <> class intArray<double>
{
private:
    double * p;
    int n;
    int error;//error=0 если ошибок нет
    //error=1 если p=NULL
    //error=2 если индекс выходит за границу
    static int count;//количество созданных объектов
    //в конструкторе наращивать, в деструкторе уменьшать

public:
    intArray();
    intArray(int n);
    intArray(const intArray &);
    ~intArray();

    double   getElem(int i);
    int    getN();
    double    getMin();
    double    getMax();
    float getAverage();
    double    getMediana();
    int    getError();
    double getDis();
    double getRMS();
    static int getCount();
    void fill();
    void sort();

    intArray operator +(const intArray &);
    intArray operator -(const intArray &);
    intArray operator *(const intArray &);
    intArray operator /(const intArray &);

    intArray operator +(int a);
    intArray operator -(int a);
    intArray operator *(int a);
    intArray operator /(int a);

    intArray &operator ++();
    intArray operator ++(int);

    intArray &operator --();
    intArray operator --(int);

    int& operator [](int a);
    void operator ()();

    void *operator new(size_t size);
    void operator delete (void* addr);

    intArray &operator =(const intArray &);
    int operator ==(const intArray &);
    int operator !=(const intArray &);
    int operator >(const intArray &);
    int operator >=(const intArray &);
    int operator <(const intArray &);
    int operator <=(const intArray &);
};

template<class Type> int intArray<Type>::count=0;
template <class Type> intArray<Type>::intArray()
{
    count++;
    p=NULL;
    n=0;
    error=1;
}
template<class Type> intArray<Type>::intArray(int n1)
{
    count++;
    n=n1;
    p=new Type[n];
    if(p==NULL) error=1;
    else error=0;
}
template<class Type> intArray<Type>::intArray(const intArray &a)
{
    count++;
    n=a.n;
    p=new Type[n];
    if(p==NULL) error=1;
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    //cout<<"\nI am copyconstructor\n";

}

template<class Type> intArray<Type>::~intArray()
{
    count--;
    delete []p;
}
template<class Type> Type intArray<Type>::getElem(int i)
{
    if(i<n)
    {
        error=0;
        return *(p+i);
    }
    else
    {
        error=2;
        return NULL;
    }
}


template<class Type>int intArray<Type>::getN()
{
    return n;
}

template<class Type> Type intArray<Type>::getMin()
{
    int min=p[0];
    for(int i=0; i<n; i++)
        if(p[i]<min) min=p[i];
    return min;
}


template<class Type> Type intArray<Type>::getMax()
{
    int max=p[0];
    for(int i=0; i<n; i++)
        if(p[i]>max) max=p[i];
    return max;

}
template<class Type>float intArray<Type>::getAverage()
{
    float aver=0;
    for(int i=0; i<n; i++)
        aver+=p[i];
    aver/=n;
    return aver;
}
template<class Type>Type intArray<Type>::getMediana()
{
    int tmp=n/2;
    return p[tmp];

}
template<class Type>int intArray<Type>::getError()
{
    return error;
}

template<class Type>double intArray<Type>::getDis()
{
    double dis=0;
    float aver=0;
    aver=getAverage();
    for(int i=0; i<n; i++)
        dis+=(p[i]-aver)*(p[i]-aver)/n;
    return dis;

}
template<class Type>double intArray<Type>::getRMS()
{
    double RMS=0;
    RMS=sqrt(getDis());
    return RMS;
}

template<class Type>int intArray<Type>::getCount()
{
    return count;
}

template<class Type>void intArray<Type>::fill()
{
    for(int i=0; i<n; i++) p[i]= rand()%100+1;

}
template<class Type>void intArray<Type>::sort()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(p[i]>p[j]) swap(p[i],p[j]);

}


template<class Type>intArray<Type> intArray<Type>::operator +(const intArray & a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new Type[n];
        tmp.n=n;
        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]+a.p[i];


        }
    }
    else
    {
        tmp.p=new Type[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]+a.p[i];
        }


        return tmp;



    }
}

template<class Type>intArray<Type> intArray<Type>::operator -(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new Type[n];
        tmp.n=n;

        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]-a.p[i];


        }
    }
    else
    {
        tmp.p=new Type[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]-a.p[i];
        }


        return tmp;



    }
}
template<class Type>intArray<Type> intArray<Type>::operator *(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new Type[n];
        tmp.n=n;

       if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]*a.p[i];


        }
    }
    else
    {
        tmp.p=new Type[a.n];
        tmp.n=a.n;

        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]*a.p[i];
        }


        return tmp;

    }
}
template<class Type>intArray<Type> intArray<Type>::operator /(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new Type[n];
        tmp.n=n;
        if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]/a.p[i];


        }
    }
    else
    {
        tmp.p=new Type[a.n];
        tmp.n=a.n;

          if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;
        for(int i=0; i<tmp.n; i++)
        {
            tmp.p[i]=p[i]/a.p[i];
        }

        return tmp;
    }
}

template<class Type>intArray<Type> intArray<Type>::operator +(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new Type[n];

     if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]+a;
    }
    return tmp;
}

template<class Type>intArray<Type> intArray<Type>::operator -(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new Type[n];

     if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]-a;
    }
    return tmp;
}
template<class Type>intArray<Type> intArray<Type>::operator *(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new Type[n];

      if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]*a;
    }
    return tmp;
}
template<class Type>intArray<Type> intArray<Type>::operator /(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new Type[n];

    if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]/a;
    }
    return tmp;
}

template<class Type>intArray<Type> &intArray<Type>::operator ++()
{
    for(int i=0; i<n; i++)
        p[i]+=1;

    return *this;
}

template<class Type>intArray<Type> intArray<Type>::operator ++(int)
{
    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]+=1;
    return tmp;
}

template<class Type>intArray<Type> &intArray<Type>::operator --()
{
    for(int i=0; i<n; i++)
        p[i]-=1;
    return *this;
}

template<class Type>intArray<Type> intArray<Type>::operator --(int)
{

    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]-=1;
    return tmp;
}

template<class Type>int &intArray<Type>::operator [](int a)
{

       int tmp=getElem(a);
       return tmp;
}
template<class Type>void intArray<Type>::operator()()
{
    for(int i=0; i<n; i++)
        cout<<p[i]<<endl;

}

template<class Type>void *intArray<Type>::operator new(size_t size)
{
    printf("operator new %d\n",size);
    void *m=malloc(size);
    if(!m) puts("out of memory!\n");
    return m;
}

template<class Type>void intArray<Type>::operator delete (void* addr)
{
    puts("operator delete");
    free(addr);
}

template<class Type>intArray<Type> &intArray<Type>::operator =(const intArray &a)// m=a=a
{
  if(this!=&a)
  {
    delete []p;
    n=a.n;
    p=new Type[n];
    if(p==NULL) error=1;
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    }
  return *this;
}

template<class Type>int intArray<Type>::operator ==(const intArray &a)
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

template<class Type>int intArray<Type>::operator !=(const intArray &a)
{
    intArray tmp1(*this),tmp2(a);
    if((tmp1==tmp2)==0)return 1;
    else return 0;
}

template<class Type>int intArray<Type>::operator >(const intArray &a)
{
    return n>a.n;
}
template<class Type>int intArray<Type>::operator >=(const intArray &a)
{
    return n>=a.n;
}
template<class Type>int intArray<Type>::operator <(const intArray &a)
{
    return n<a.n;
}
template<class Type>int intArray<Type>::operator <=(const intArray &a)
{
    return n<=a.n;
}


/*intArray operator +(int a, const intArray &b)
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
}*/




#endif // INTARRAY_H_INCLUDED

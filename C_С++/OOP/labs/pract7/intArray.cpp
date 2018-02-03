#include <iostream>
#include "intArray.h"
#include <ctime>
#include<cmath>
#include<cstdlib>
#include <stdio.h>
using namespace std;
int intArray::count=0;

intArray::intArray()
{
  n = 0;
  p = NULL;
  count++;

}

intArray::intArray(int s)
{

  n = s;
  p = new int[n];
  if(p==NULL)  cout<<"Perepolnenie pamyati";
  count++;
}


intArray::intArray(const intArray & mas)
{
  n = mas.n;
  p = new int[n];
  if(p==NULL) cout<<"Perepolnenie pamyati";

  count++;
  for(int i = 0; i<n; i++) p[i]=mas.p[i];

}

intArray::~intArray()
{
  delete []p;
  count--;
}

int &intArray::getElem(int i)
{
  return *(p+i);
}

int intArray::getMin()
{
  int min=p[0];
  for(int i=1; i<n; i++)
    if(p[i]<min) min=p[i];

  return min;
}
int intArray::getMax()
{
  int max = p[0];
  for(int i=1; i<n; i++)
    if(p[i]>max) max=p[i];

  return max;
}

float intArray::getAverage()
{
  int sum=0;
  for(int i=0; i<n; i++) {
    sum+=p[i];
  }
  return (float)sum/n;
}

int intArray::getMediana()
{
  this->sort();
  return p[n/2];
}
/*
int intArray::getEror()
{
    if(error==1)cout<<"Razmernosti ob'ektov ne sovpadyut\n";//размер при инициализации и объявление не совпадают.не может определить тип данных массива
    if(error==2)cout <<"indeks vyshel za granicu massiva\n";
    if(error==3)cout<<"perepolnenie pamyati\n";
    else return 0;
}*/

double intArray::getDis()
{
    double  sum=0;
    float tmp=getAverage();
    for (int i=0; i<n; i++)
    {
        sum+=pow((p[i]-tmp),2);
    }
    return sum/n;
}

double intArray::getRMS()
{
    return sqrt(getDis());
}
void intArray::fill()
{
  for(int i=0; i<n; i++)
    p[i]=rand()%100;
}

void intArray::sort()
{
  int tmp;
  for(int i = 0; i < n - 1; ++i){
    for(int j = 0; j < n - 1; ++j) {
      if (p[j + 1] < p[j]) {
        tmp = p[j + 1];
        p[j + 1] = p[j];
        p[j] = tmp;
      }
    }
  }
}
intArray & intArray::operator -()
{
    for(int i=0; i<n; i++)p[i]*=-1;
    return *this;
}
intArray intArray::operator +(const intArray &b)
{

  if(n==b.n)
  {
    intArray tmp(n);
    for(int i=0; i<n; i++)
      tmp.p[i]=p[i]+b.p[i];
    return tmp;
  }
  else
  {
    //error=1;
    cout<<"Error of size";
    return 0;
  }
}
intArray intArray::operator -(const intArray &b)
{
  if(n==b.n)
  {
    intArray tmp(n);
    for(int i=0; i<n; i++)
      tmp.p[i]=p[i]-b.p[i];
    return tmp;
  }
  else
  {

      cout<<"Error of size";
    return 0;
  }
}
intArray intArray::operator *(const intArray &b)
{
  if(n==b.n)
  {
    intArray tmp(n);
    for(int i=0; i<n; i++)
      tmp.p[i]=p[i]*b.p[i];
    return tmp;
  }
  else
  {

      cout<<"Error of size";
    return 0;
  }
}
intArray intArray::operator /(const intArray &b)
{
  if(n==b.n)
  {
    intArray tmp(n);
    for(int i=0; i<n; i++)
    {
        if(b.p[i])tmp.p[i]=p[i]/b.p[i];
        else cout <<"division by 0\n";
    }
    return tmp;
  }
  else
  {
   cout<<"Error of size";
    return 0;
  }
}

intArray intArray::operator +(int a)
{
  intArray tmp(n);
  for(int i=0; i<n; i++)tmp.p[i]=p[i]+a;
  return tmp;
}
intArray intArray::operator -(int a)
{
  intArray tmp(n);
  for(int i=0; i<n; i++)tmp.p[i]=p[i]-a;
  return tmp;
}
intArray intArray::operator *(int a)
{
  intArray tmp(n);
  for(int i=0; i<n; i++)tmp.p[i]=p[i]*a;
  return tmp;
}
intArray intArray::operator /(int a)
{
  intArray tmp(n);
  if(!a) {
    cout<<"\nDivision by zero!\n";
    return 0;
  }
  for(int i=0; i<n; i++)tmp.p[i]=p[i]/a;
  return tmp;
}

intArray & intArray::operator++()
{

    for(int i=0; i<n; i++)p[i]++;
    return *this;
}
intArray  intArray::operator++(int a)
{
    intArray tmp(a);
    for (int i=0; i<n; i++) ++p[i];
    return tmp;
}
intArray& intArray::operator--()
{
    for(int i=0; i<n; i++)p[i]--;
    return *this;
}
intArray  intArray::operator--(int a)
{
    intArray tmp(a);
    for (int i=0; i<n; i++) --p[i];
    return tmp;
}

int& intArray::operator[](int a)
{
  if(a>=n)cout<<"indeks vishel za granicu massiva";
  return(p[a]);
}

void intArray::operator ()()
{

  printf("\n");
  for(int i=0;i<n;i++)
  {
    printf("%d ",p[i]);
  }
  printf("\n");
  return;
}

void *intArray::operator new(size_t size)
{
  return malloc(size);
}
void intArray::operator delete(void *addr)
{
  free(addr);
}

intArray& intArray::operator =(const intArray &b)
{
  if(this!=&b) {
    n=b.n;
    delete []p;
    p=new int[n];
    for(int i=0; i<n; i++) {
      p[i]=b.p[i];
    }
  }
  else  cout<<"Error of size";
  return *this;
}

int intArray::operator==(const intArray &b)
{
   for(int i=0;i<n;i++)
      if(p[i]!=b.p[i])return 0;
    return 1;
}

int intArray::operator >(const intArray &b)
{
    for(int i=0;i<n;i++)
      if(p[i]<b.p[i])return 0;
    return 1;

}

int intArray::operator<(const intArray &b)
{
     for(int i=0;i<n;i++)
      if(p[i]>b.p[i])return 0;
    return 1;

}


int intArray::operator!=(const intArray &b)
{
   for(int i=0;i<n;i++)
      if(p[i]==b.p[i])return 0;
    return 1;
}

int intArray::operator<=(const intArray &b)
{
   for(int i=0;i<n;i++)
      if(p[i]>=b.p[i])return 0;
    return 1;
}

int intArray::operator>=(const intArray &b)
{
   for(int i=0;i<n;i++)
      if(p[i]<=b.p[i])return 0;
    return 1;
}
intArray operator +(int a, const intArray &b)
{

    intArray tmp(b);
    for (int i=0; i<tmp.n; i++) tmp.p[i]=b.p[i]+a;
    return tmp;
}
intArray operator -(int a, const intArray &b)
{
    intArray tmp(b);
    for (int i=0; i<tmp.n; i++) tmp.p[i]=a-b.p[i];
    return tmp;
}
intArray operator *(int a, const intArray &b)
{
    intArray tmp(b);
    for (int i=0; i<tmp.n; i++) tmp.p[i]=a*b.p[i];
    return tmp;
}
intArray operator /(int a, const intArray &b)
{
    intArray tmp(b);
    for (int i=0; i<tmp.n; i++) tmp.p[i]=a/b.p[i];
    return tmp;
}
ostream& operator<<(ostream& to, const intArray &V)//передача по ссылки
{
    int i;
    for (i=0; i<V.n; i++)
    {
        output<<V.p[i]<<" ";
        if ((i+1)%10==0)
            output<<endl;
    }
    if (i%10==0)
        output<<endl;
    return output;
}

istream& operator>>(istream& in,  intArray &V)//передача по ссылки
{
  for (int i=0; i<V.n; i++)input>>V.p[i];
  return input;
}



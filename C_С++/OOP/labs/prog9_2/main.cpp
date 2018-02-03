#include <iostream>
#include <stdio.h>
#include "intArray.h"
using namespace std;

int main()
{
try{
    intArray a(7),b(3),c,k,*k1,t(12);
    a.fill();
    cout<<"output a:\n";
    a();
    cout<<"Sort a"<<endl;
    a.sort();
    a();
    cout<<"getdis: "<<a.getDis()<<endl;
    cout<<"getRMS: "<<a.getRMS()<<endl;
    b.fill();
    cout<<"output B\n";
    b();
    cout<<"c=b\n";
    c=b;
    cout<<"output C:\n";
    c();
    cout<<"c.getmax="<<c.getMax()<<endl;
    cout<<"c.getmin="<<c.getMin()<<endl;
    cout<<"c.getavereage="<<c.getAverage()<<endl;
    cout<<"c.geterror="<<c.getError()<<endl;
    cout<<"c.getelement(3)="<<c.getElem(3)<<endl;
    cout<<"c.getN="<<c.getN()<<endl;
    cout<<"c=a+b\n";
    c=a+b;
    c();
    cout<<"c=a-b\n";
    c=a-b;
    c();
    cout<<"c=a*b\n";
    c=a*b;
    c();
    cout<<"c=a/b\n";
    c=a/b;
    c();
    int tmp=9;
    cout<<"a:\n";
    a();
    cout<<"c=a+9\n";
    c=a+tmp;
    c();
     cout<<"c=a-9\n";
    c=a-tmp;
    c();
     cout<<"c=a*9\n";
    c=a*tmp;
    c();
     cout<<"c=a/9\n";
    c=a/tmp;
    c();
    ++c;
    cout<<"++c="<<endl;
    c();
    c++;
    cout<<"c++\n";
    c();
    --c;
    cout<<"--c\n";
    c();
    c--;
    cout<<"c--\n";
    c();
    cout<<"c[0]="<<c[0]<<" c[1]="<<c[1]<<endl;
    cout<<"getcount="<<c.getCount()<<endl;
    cout<<"operator new:\n";
    k1=new(intArray);
    cout<<"operator delete:\n";
    delete(k1);
    k=a;
    cout<<"c==a: "<<(c==a)<<" k=a: "<<(k==a)<<endl;
    cout<<"c!=a: "<<(c!=a)<<" k!=a: "<<(k!=a)<<endl;
    cout<<"c>a: "<<(c>a)<<" k>a: "<<(k>a)<<endl;
    cout<<"c>=a: "<<(c>=a)<<" k>=a: "<<(k>=a)<<endl;
    cout<<"c<a: "<<(c<a)<<" k<a: "<<(k<a)<<endl;
    cout<<"c<=a: "<<(c<=a)<<" k<=a: "<<(k<=a)<<endl;
    cout<<"k=t-cm=\n";
    int tm1=8;
    k=tm1+c;
    k();
     cout<<"k=c-tm=\n";

    k=c-tm1;
    k();
     cout<<"k=tm*c=\n";

    k=tm1*c;
    k();
     cout<<"k=c/tm=\n";

    k=c/tm1;
    k();
}
catch(int i)
{
    char *s;
    if(i==0) s="Mistakes are absent!";
    if(i==1) s="P=NULL!";
    if(i==2) s="Index of array is overflown!";
    printf("Error=%d: %s",i,s);
}
catch(intArray::Size)
{
    cout<<"Size is overflown!";
}
    return 0;
}

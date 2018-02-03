#include <iostream>
#include "intArray.h"
using namespace std;
//определение специализированного класса

 int intArray<double>::count=0;
 intArray<double>::intArray()
{
    count++;
    p=NULL;
    n=0;
    error=1;
}
intArray<double>::intArray(int n1)
{
    count++;
    n=n1;
    p=new double[n];
    if(p==NULL) error=1;
    else error=0;
}
intArray<double>::intArray(const intArray &a)
{
    count++;
    n=a.n;
    p=new double[n];
    if(p==NULL) error=1;
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    //cout<<"\nI am copyconstructor\n";

}

intArray<double>::~intArray()
{
    count--;
    delete []p;
}
double intArray<double>::getElem(int i)
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


int intArray<double>::getN()
{
    return n;
}

double intArray<double>::getMin()
{
    int min=p[0];
    for(int i=0; i<n; i++)
        if(p[i]<min) min=p[i];
    return min;
}


double intArray<double>::getMax()
{
    int max=p[0];
    for(int i=0; i<n; i++)
        if(p[i]>max) max=p[i];
    return max;

}
float intArray<double>::getAverage()
{
    float aver=0;
    for(int i=0; i<n; i++)
        aver+=p[i];
    aver/=n;
    return aver;
}
double intArray<double>::getMediana()
{
    int tmp=n/2;
    return p[tmp];

}
int intArray<double>::getError()
{
    return error;
}

double intArray<double>::getDis()
{
    double dis=0;
    float aver=0;
    aver=getAverage();
    for(int i=0; i<n; i++)
        dis+=(p[i]-aver)*(p[i]-aver)/n;
    return dis;

}
double intArray<double>::getRMS()
{
    double RMS=0;
    RMS=sqrt(getDis());
    return RMS;
}
int intArray<double>::getCount()
{
    return count;
}

void intArray<double>::fill()
{
    for(int i=0; i<n; i++) p[i]= rand()%100+1;

}
void intArray<double>::sort()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(p[i]>p[j]) swap(p[i],p[j]);

}

intArray<double> intArray<double>::operator +(const intArray & a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new double[n];
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
        tmp.p=new double[a.n];
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

intArray<double> intArray<double>::operator -(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new double[n];
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
        tmp.p=new double[a.n];
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
intArray<double> intArray<double>::operator *(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new double[n];
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
        tmp.p=new double[a.n];
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
intArray<double> intArray<double>::operator /(const intArray &a)
{
    intArray tmp;
    if(n<a.n)
    {
        tmp.p=new double[n];
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
        tmp.p=new double[a.n];
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

intArray<double> intArray<double>::operator +(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new double[n];

     if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]+a;
    }
    return tmp;
}
intArray<double> intArray<double>::operator -(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new double[n];

     if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]-a;
    }
    return tmp;
}
intArray<double> intArray<double>::operator *(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new double[n];

      if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]*a;
    }
    return tmp;
}
intArray<double> intArray<double>::operator /(int a)
{
    intArray tmp;
    tmp.n=n;
    tmp.p=new double[n];

    if(tmp.p==NULL) tmp.error=1;
        else tmp.error=0;

    for(int i=0; i<tmp.n; i++)
    {
        tmp.p[i]=p[i]/a;
    }
    return tmp;
}

intArray<double> &intArray<double>::operator ++()
{
    for(int i=0; i<n; i++)
        p[i]+=1;

    return *this;
}

intArray<double> intArray<double>::operator ++(int)
{
    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]+=1;
    return tmp;
}

intArray<double> &intArray<double>::operator --()
{
    for(int i=0; i<n; i++)
        p[i]-=1;
    return *this;
}
intArray<double> intArray<double>::operator --(int)
{

    intArray tmp(*this);
    for(int i=0; i<n; i++)
        p[i]-=1;
    return tmp;
}

int &intArray<double>::operator [](int a)
{

       int tmp=getElem(a);
       return tmp;
}
void intArray<double>::operator()()
{
    for(int i=0; i<n; i++)
        cout<<p[i]<<endl;

}

void *intArray<double>::operator new(size_t size)
{
    printf("operator new %d\n",size);
    void *m=malloc(size);
    if(!m) puts("out of memory!\n");
    return m;
}

void intArray<double>::operator delete (void* addr)
{
    puts("operator delete");
    free(addr);
}

intArray<double> &intArray<double>::operator =(const intArray &a)// m=a=a
{
  if(this!=&a)
  {
    delete []p;
    n=a.n;
    p=new double[n];
    if(p==NULL) error=1;
    else error=0;
    for(int i=0; i<n; i++)
        p[i]=a.p[i];
    }
  return *this;
}

int intArray<double>::operator ==(const intArray &a)
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

int intArray<double>::operator !=(const intArray &a)
{
    intArray tmp1(*this),tmp2(a);
    if((tmp1==tmp2)==0)return 1;
    else return 0;
}
int intArray<double>::operator >(const intArray &a)
{
    return n>a.n;
}
int intArray<double>::operator >=(const intArray &a)
{
    return n>=a.n;
}
int intArray<double>::operator <(const intArray &a)
{
    return n<a.n;
}
int intArray<double>::operator <=(const intArray &a)
{
    return n<=a.n;
}

int main()
{
    cout<<"\t********<float>***********"<<endl;
    intArray<float> a(7),b(3),c,k,*k1;
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
    cout<<"c.getelement(4)="<<c.getElem(4)<<endl;
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
    k1=new(intArray<float>);
    cout<<"operator delete:\n";
    delete(k1);
    k=a;
    cout<<"c==a: "<<(c==a)<<" k=a: "<<(k==a)<<endl;
    cout<<"c!=a: "<<(c!=a)<<" k!=a: "<<(k!=a)<<endl;
    cout<<"c>a: "<<(c>a)<<" k>a: "<<(k>a)<<endl;
    cout<<"c>=a: "<<(c>=a)<<" k>=a: "<<(k>=a)<<endl;
    cout<<"c<a: "<<(c<a)<<" k<a: "<<(k<a)<<endl;
    cout<<"c<=a: "<<(c<=a)<<" k<=a: "<<(k<=a)<<endl;
    /*cout<<"k=t+cm=\n";
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
    k();*/
    cout<<"\t********<int>***********"<<endl;
    intArray<int> a1(7),b1(3),c1,k2,*k3;
    a1.fill();
    cout<<"output a1:\n";
    a1();
    cout<<"Sort a1"<<endl;
    a1.sort();
    a1();
    cout<<"getdis: "<<a1.getDis()<<endl;
    cout<<"getRMS: "<<a1.getRMS()<<endl;
    b1.fill();
    cout<<"output B1\n";
    b1();
    cout<<"c1=b1\n";
    c1=b1;
    cout<<"output C1:\n";
    c1();
    cout<<"c1.getmax="<<c1.getMax()<<endl;
    cout<<"c1.getmin="<<c1.getMin()<<endl;
    cout<<"c1.getavereage="<<c1.getAverage()<<endl;
    cout<<"c1.geterror="<<c1.getError()<<endl;
    cout<<"c1.getelement(4)="<<c1.getElem(4)<<endl;
    cout<<"c1.getN="<<c1.getN()<<endl;
    cout<<"c1=a1+b1\n";
    c1=a1+b1;
    c1();
    cout<<"c1=a1-b1\n";
    c1=a1-b1;
    c1();
    cout<<"c=a*b\n";
    c1=a1*b1;
    c1();
    cout<<"c1=a1/b1\n";
    c1=a1/b1;
    c1();
    int tmp1=9;
    cout<<"a1:\n";
    a1();
    cout<<"c1=a1+9\n";
    c1=a1+tmp1;
    c1();
     cout<<"c1=a1-9\n";
    c1=a1-tmp1;
    c1();
     cout<<"c1=a1*9\n";
    c1=a1*tmp1;
    c1();
     cout<<"c1=a1/9\n";
    c1=a1/tmp1;
    c1();
    ++c1;
    cout<<"++c1="<<endl;
    c1();
    c1++;
    cout<<"c1++\n";
    c1();
    --c1;
    cout<<"--c1\n";
    c1();
    c1--;
    cout<<"c1--\n";
    c1();
    cout<<"c1[0]="<<c1[0]<<" c1[1]="<<c1[1]<<endl;
    cout<<"getcount="<<c1.getCount()<<endl;
    cout<<"operator new:\n";
    k3=new(intArray<int>);
    cout<<"operator delete:\n";
    delete(k3);
    k2=a1;
    cout<<"c1==a1: "<<(c1==a1)<<" k2=a1: "<<(k2==a1)<<endl;
    cout<<"c1!=a1: "<<(c1!=a1)<<" k2!=a1: "<<(k2!=a1)<<endl;
    cout<<"c1>a1: "<<(c1>a1)<<" k2>a1: "<<(k2>a1)<<endl;
    cout<<"c1>=a1: "<<(c1>=a1)<<" k2>=a1: "<<(k2>=a1)<<endl;
    cout<<"c1<a1: "<<(c1<a1)<<" k2<a1: "<<(k2<a1)<<endl;
    cout<<"c1<=a1: "<<(c1<=a1)<<" k2<=a1: "<<(k2<=a1)<<endl;

cout<<"\t********<double>***********"<<endl;
    intArray<double> a3(7),b3(3),c3,k5,*k4;
    a3.fill();
    cout<<"output a3:\n";
    a3();
    cout<<"Sort a3"<<endl;
    a3.sort();
    a3();
    cout<<"getdis: "<<a3.getDis()<<endl;
    cout<<"getRMS: "<<a3.getRMS()<<endl;
    b3.fill();
    cout<<"output B\n";
    b3();
    cout<<"c3=b3\n";
    c3=b3;
    cout<<"output C3:\n";
    c3();
    cout<<"c3.getmax="<<c3.getMax()<<endl;
    cout<<"c3.getmin="<<c3.getMin()<<endl;
    cout<<"c3.getavereage="<<c3.getAverage()<<endl;
    cout<<"c3.geterror="<<c3.getError()<<endl;
    cout<<"c3.getelement(4)="<<c3.getElem(4)<<endl;
    cout<<"c3.getN="<<c3.getN()<<endl;
    cout<<"c3=a3+b3\n";
    c3=a3+b3;
    c3();
    cout<<"c3=a3-b3\n";
    c3=a3-b3;
    c3();
    cout<<"c3=a3*b3\n";
    c3=a3*b3;
    c3();
    cout<<"c3=a3/b3\n";
    c3=a3/b3;
    c3();
    int tmp3=9;
    cout<<"a3:\n";
    a3();
    cout<<"c3=a3+9\n";
    c3=a3+tmp3;
    c3();
     cout<<"c3=a3-9\n";
    c3=a3-tmp3;
    c3();
     cout<<"c3=a3*9\n";
    c3=a3*tmp3;
    c3();
     cout<<"c3=a3/9\n";
    c3=a3/tmp3;
    c3();
    ++c3;
    cout<<"++c3="<<endl;
    c3();
    c3++;
    cout<<"c3++\n";
    c3();
    --c3;
    cout<<"--c3\n";
    c3();
    c3--;
    cout<<"c3--\n";
    c3();
    cout<<"c3[0]="<<c3[0]<<" c3[1]="<<c3[1]<<endl;
    cout<<"getcount="<<c3.getCount()<<endl;
    cout<<"operator new:\n";
    k4=new(intArray<double>);
    cout<<"operator delete:\n";
    delete(k4);
    k5=a3;
    cout<<"c3==a3: "<<(c3==a3)<<" k5=a3: "<<(k5==a3)<<endl;
    cout<<"c3!=a3: "<<(c3!=a3)<<" k5!=a3: "<<(k5!=a3)<<endl;
    cout<<"c3>a3: "<<(c3>a3)<<" k5>a3: "<<(k5>a3)<<endl;
    cout<<"c3>=a3: "<<(c3>=a3)<<" k5>=a3: "<<(k5>=a3)<<endl;
    cout<<"c3<a3: "<<(c3<a3)<<" k5<a3: "<<(k5<a3)<<endl;
    cout<<"c3<=a3: "<<(c3<=a3)<<" k5<=a3: "<<(k5<=a3)<<endl;

    return 0;
}

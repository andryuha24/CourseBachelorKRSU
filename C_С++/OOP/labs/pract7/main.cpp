#include <iostream>
#include <ctime>
#include<cstdlib>
#include <stdio.h>
#include "intArray.h"
using namespace std;

int main()
{   srand(time(NULL));
    intArray a(11),*b ,c(5),d(5),e(5);
    a.fill();
    a();
    a.sort();
    a();
    b = new intArray(11);
    b->fill();
    /*if(a==*b) cout<<"a=b"<<endl;
    if(a!=*b) cout<<"a!=b"<<endl;
    if(a>*b) cout<<"a>b"<<endl;
    if(a>=*b) cout<<"a>=b"<<endl;
    if(a<*b) cout<<"a<b"<<endl;
    if(a<=*b) cout<<"a<=b"<<endl;
     cout<<"count="<<a.getCount()<<endl;
    delete b;
    cout<<"count="<<a.getCount()<<endl;*/
    e.fill();
    c.fill();
    d=a+c;     //различаются размерности
   d.getEror();
   d=e+c;
    d=e-c;
    d=e*c;
    d=e/c;
    d=e+5;
    d=3+e;
    d=4*e;
    c++;
    c--;
    ++c;
    --c;
    printf("\na max %d",a.getMax());
     printf("\na min %d",a.getMin());
    printf("\na srednee %.2f",a.getAverage());
    printf("\na mediana %2d",a.getMediana());
    printf("\na Disp %.2f",a.getDis());
    printf("\na RMS %.2f",a.getRMS());
    cout<<a;
    return 0;
}

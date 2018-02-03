#include <iostream>
#include <stdio.h>
#include "Fract.h"
using namespace std;

int main()
{
    int cel,ch,zn,i,rezult;
    Fract c;
    printf("                        y \n");
    printf(" Vviedte drob v vvide X -\n");
    printf("                        z\n");
    cout<<"1. "<<endl<<"Celoe: ";
    cin>>cel;
    cout<<"Chislitel': ";
    cin >> ch;
    cout<<"Znamenatel': ";
    cin >>zn;
    Fract a(cel, ch,zn);
    cout<<"2. "<<endl<<"Celoe: ";
    cin>>cel;
    cout<<"Chislitel': ";
    cin >> ch;
    cout<<"Znamenatel': ";
    cin >>zn;
    Fract b(cel,ch,zn);//(2,10,8),s,r,m,d;
    cout<<"\nDrob 1: ";
    a.show();
    cout<<"\nDrob 2: ";
    b.show();
    printf("\nViberite operaciyu :\n");
    printf("    1.Summa drobei.\n");
    printf("    2.Raznost drobei.\n");
    printf("    3.Proizvedenie drobei.\n");
    printf("    4.delenie drobei.\n");
    printf("    5.Sravnenie drobei na ravenstvo.\n");
    printf("    6.Sravnenie drobei na '>'.\n");
    printf("    7.Sravnenie drobei na '<'.\n");
    cin >> i;
    switch(i)
    {
    case 1:
        c = a.sum(b);
        c.show();
        break;
    case 2:
        c = a.dif(b);
        c.show();
        break;
    case 3:
        c = a.mul(b);
        c.show();
        break;
    case 4:
        c = a.dev(b);
        c.show();
        break;
    case 5:
    {
         if (a.equals(b))cout<<"Drob1 = Drob2";
         else cout<<"Drob1 != Drob2";
    }
    break;
    case 6:
    {
         if (a.more(b))cout<<"Drob1 > Drob2";
         else cout<<"Drob1 < Drob2";
    }
    break;
    case 7:
    {
         if (a.less(b))cout<<"Drob1 < Drob2";
         else cout<<"Drob1 > Drob2";
    }
    break;
    default:
        return 0;
    }

    return 0;
}

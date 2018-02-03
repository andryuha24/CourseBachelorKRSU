#include <iostream>
#include <stdio.h>
#include "Fract.h"
using namespace std;

int main()
{

    Fract a(1,5,6),b,c,d;
    printf("                        y \n");
    printf(" Vviedte drob v vvide X -\n");
    printf("                        z\n");
    cout<<"1.Drob2: ";
    cin>>b;
    cout<<"\n2.Drob3: ";
    cin >> c;
    cout<<"Drob1: "<<a<<endl<<"Drob2: "<<b<<endl<<"Drob3: "<<c;
    printf("\nViberite operaciyu :\n");
    printf("    1.Summa drobei.\n");
    printf("    2.Raznost drobei.\n");
    printf("    3.Proizvedenie drobei.\n");
    printf("    4.delenie drobei.\n");
    printf("    5.Predstavit' drob' v desyatichnoi forme.\n");
    printf("    6.Deistvie s naturalnim chislom.\n");
    printf("    7.Sravnenie drobei na ravenstvo.\n");
    printf("    8.Sravnenie drobei na '>'.\n");
    printf("    9.Sravnenie drobei na '<'.\n");
    printf("    10.Dekrement i inkrement.\n");
    printf("    11.Poluchit' chislitel, znamenatel', celuyu chast'.\n");

    int i;
    cin >> i;
    switch(i)
    {
    case 1:
        d = a+b;
        cout <<d;
        break;
    case 2:
        d = c-b;
        cout <<d;
        break;
    case 3:
        d = a*c;
        cout << d;
        break;
    case 4:
        {
            int j;
            cout <<"Vibirite delenie: 1. - celochislennoe | 2. - po modulyu\n";
            cin >> j;
            switch(j)
            {
            case 1:
                cout << "\n1. Drob1/Drob2\n";
                d = a/b;
                cout << d;
                break;
            case 2:
                int n;
                cout<<"\nVvedite chislo: ";
                cin>>n;
                cout << "\n1. Drob2%n: ";
                d= b%n;
                cout << d;
                break;
            }
        }
        break;
     case 5:cout<<"Drob1: "<< (double)a;break;
     case 6:
          int n,k;
          cout<<"\nVvedite chislo: ";
          cin>>n;
          cout<<"\nVibirite operacyu: 1.+, 2.-, 3.*, 4./ \n";
          cin>>k;
          switch(k)
          {
            case 1: cout<<n<<"+"<<c<<"="<<n+c;break;
            case 2: cout<<n<<"-"<<c<<"="<<n-c;break;
            case 3: cout<<n<<"*"<<c<<"="<<n*c;break;
            case 4: cout<<n<<"/"<<c<<"="<<n/c;break;
            default: return 0;
          }
          break;
     case 7:
     {
          if (a==b)cout<<"Drob1 = Drob2";
          else cout<<"Drob1 != Drob2";
     }
     break;
     case 8:
     {
          if (a>b)cout<<"Drob1 > Drob2";
          else cout<<"Drob1 < Drob2";
     }
     break;
     case 9:
     {
          if (a<b)cout<<"Drob1 < Drob2";
          else cout<<"Drob1 > Drob2";
     }
     break;
     case 10:
         a++;
         b--;
        cout<<"\nDrob1++ : "<<a;cout<<"\nDrob2-- : "<<b;break;
     case 11:
        int m;
        cout<<"Drob1. Viviste celuyu, chisl ili znam chast': 1,2,3\n";
        cin>>k;
        cout<<endl<<a[k];break;
    default:
        return 0;
    }

    return 0;
}

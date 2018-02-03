#include <iostream>
#include<stdio.h>
#include <windows.h>
#include "MTime.h"
using namespace std;

int main()
{
    int ch1,min1,sec1;
    int ch2,min2,sec2;
    int i;
    MTime a;
    cout<<" Vvedite vremya: chasi, minuti, secundi\n";
    cin >> ch1;
    cin >> min1;
    cin >> sec1;
    MTime b(ch1,min1,sec1);
    printf("\nViberite operaciyu :\n");
    printf("    1.Sistemnoe vremya\n");
    printf("    2.Polzovatelskoe vremya.\n");
    printf("    3.Raznost' mejdu sistemnim i polzovatelskim vremenem.\n");
    printf("    4.Timer.\n");
    printf("    5.Sravnenie vremeni na ravenstvo.\n");
    printf("    6.Sravnenie vremeni na '>'.\n");
    printf("    7.Sravnenie vremeni na '<'.\n");
    cin >> i;
    switch(i)
    {
    case 1:
        a.showTime();
        break;
    case 2:
        b.showTime();
        break;
    case 3:
        {
            MTime d;
            d=a.diffTime(b);
            printf("\n Systemnoe vremya: ");
            a.showTime();
            printf("\n Polzovatelskoe vremya: ");
            b.showTime();
            printf("\n Raznica: ");
            d.showTime();
        }
        break;
    case 4:
        {
            cout<<"\nInput timer: ";
            cin >> ch2;
            cin >> min2;
            cin >> sec2;
            MTime c(ch2,min2,sec2);
            while(1)
            {
                system("cls");
                c.showTime();
                Sleep(1000);
                c.inkr();
            }
        }
        break;
    case 5:
        {
          if (a.equals(b))cout<<" Systemnoe vremya = Polzovatelskomu vremeni";
          else cout<<" Systemnoe vremya != Polzovatelskomu vremeni";
        }
        break;
    case 6:
        {
          if (a.more(b))cout<<" Systemnoe vremya > Polzovatelskomu vremeni";
          else cout<<" Systemnoe vremya < Polzovatelskomu vremeni";
        }
        break;
    case 7:
        {
          if (a.less(b))cout<<" Systemnoe vremya < Polzovatelskomu vremeni";
          else cout<<" Systemnoe vremya > Polzovatelskomu vremeni";
        }
        break;
    default:
        return 0;
    }

}

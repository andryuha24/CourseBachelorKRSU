#include <iostream>
#include <stdio.h>
#include "MDate.h"
using namespace std;

int main()
{
    int y1,m1,d1, i;
    MDate a;
    cout<<" Vvedite datu: den, mesyac, god\n";
    cin >> d1;
    cin >> m1;
    cin >> y1;
    MDate b(y1,m1,d1);
    b.showDate(1);
    cout<<endl;
    a.showDate(1);
   //cout <<" "<<a.diffDate(b,3);
    printf("\nViberite operaciyu :\n");
    printf("    1.Sistemnaya data\n");
    printf("    2.Polzovatelskaya data.\n");
    printf("    3.Raznost' mejdu sistemnoi i polzovatelskoi datoi.\n");
    printf("    4.Sravnenie vremeni na ravenstvo.\n");
    printf("    5.Sravnenie vremeni na '>'.\n");
    printf("    6.Sravnenie vremeni na '<'.\n");
    cin >> i;
    switch(i)
    {
    case 1:
        {
          int j;
          printf("\nViberite formu vivoda :\n");
          printf("    1.“15.12.2006”\n");
          printf("    2.“15 December 2006”\n");
          cin >>j;
          switch(j)
          {
           case 1:a.showDate(1);break;
           case 2:a.showDate(2);break;
          }
        }
        break;
    case 2:
        {
          int k;
          printf("\nViberite formu vivoda :\n");
          printf("    1.“15.12.2006”\n");
          printf("    2.“15 December 2006”\n");
          cin >>k;
          switch(k)
          {
           case 1:b.showDate(1);break;
           case 2:b.showDate(2);break;
          }
        }
        break;
    case 3:
        {
            int m;
            printf("\n Systemnoe vremya: ");
            a.showDate(1);
            printf("\n Polzovatelskoe vremya: ");
            b.showDate(1);
            printf("\nViberite formu vivoda raznici :\n");
            printf("    1.v dnyah\n");
            printf("    2.v mesyacah\n");
            printf("    3.v godah\n");
            cin >>m;
            printf("\n Raznica: ");
            switch(m)
            {
              case 1:cout<<a.diffDate(b,1);break;
              case 2:cout<<a.diffDate(b,2);break;
              case 3:cout<<a.diffDate(b,3);break;
            }
        }
        break;
    case 4:
        {
          if (a.equals(b))cout<<" Systemnaya data = Polzovatelskoi date";
          else cout<<" Systemnaya data  != Polzovatelskomu vremeni";
        }
        break;
    case 5:
        {
          if (a.more(b))cout<<" Systemnoe vremya > Polzovatelskomu vremeni";
          else cout<<" Systemnoe vremya < Polzovatelskomu vremeni";
        }
        break;
    case 6:
        {
          if (a.less(b))cout<<" Systemnoe vremya < Polzovatelskomu vremeni";
          else cout<<" Systemnoe vremya > Polzovatelskomu vremeni";
        }
        break;
    default:
        return 0;
    }
}

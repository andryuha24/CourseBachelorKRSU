#include <iostream>
#include "MString.h"
#include <stdio.h>
using namespace std;

int MSE()
{
    String mas[5]= {"Privet","China","Russia","Voskresene","ponedelniki"};

    String s1,s2;
    for(int i=0; i<5; i++)
    {
        if(mas[i].getLength()==11) s1 = mas[i];
        if(mas[i]=="Voskresene")s2=mas[i];
    }
    cout << "Element s dlinnoi 11: "<<s1<<endl;
    cout << "Element Voskresenie naiden: "<<s2<<endl;
    return 0;
}

int ShowStrings()
{
    int y1,m1,d1, i;
    String s1,s2;
    String s3("hello");
    String sum;
    cout<<" Vvedite stroki: ";
    cin >> s1;
    cin >> s2;
    printf("\nViberite operaciyu :\n");
    printf("    1.Vivesti stroki\n");
    printf("    2.Skleit' stroki\n");
    printf("    3.Konkatenaciya strok\n");
    printf("    4.Sravnenie strok na ravenstvo.\n");
    printf("    5.Sravnenie strok na '>'.\n");
    printf("    6.Sravnenie strok na '<='.\n");
    printf("    7.Uslovie s massivom elementov tipa String\n");
    cin >> i;
    switch(i)
    {
    case 1:
    {
        printf("\nVivesti stroki :\n");
        cout<<s1<<endl;
        cout <<s2;
    }
    break;
    case 2:
    {
        printf("2.Skleit' stroki\n");
        cout<<"sum="<<s1+s2<<endl;
    }

    break;
    case 3:
    {
        printf("\n Konkatenaciya strok:\n ");
        sum=s1+s2;
        sum+=s1;
        cout <<sum<<endl;
    }
    break;
    case 4:
    {
        if (s1==s2)cout<<" Pervaya stroka ravna vtroi ";
        else cout<<" Pervaya stroka neravna vtroi";
    }
    break;
    case 5:
    {
        if (s1>s2)cout<<" Pervaya stroka bolshe vtroi ";
        else cout<<" Pervaya stroka neravna vtroi";
    }
    break;
    case 6:
    {
        if (s1<=s2)cout<<" Pervaya stroka <= vtroi stroki";
        else cout<<" Pervaya stroka >= vtroi stroki";
    }
    break;
    case 7:
        MSE();
        break;
    default:
        return 0;
    }
}

int main()
{
    ShowStrings();
}

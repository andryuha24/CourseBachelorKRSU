#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "komplect.h"

int main()
{
      Komplect mas[10];
      struct Komplect x;
      int n, m, i,j;
      for(n=0; n < 10; n++)
      {
          printf("%d. Input  Name, Type, Nominal, Amount: ",n+1);
          scanf("%s",mas[n].name);
          if(!strcmp(mas[n].name,"***"))break;
          scanf("%s", &mas[n].type);
          scanf("%f", &mas[n].coast);
          scanf("%d", &mas[n].number);
      }

    printf(" \n ---------------------------------\n");
    printf("|    Vedomost' komplectuyushih    |\n");
    printf("|---------------------------------|\n");
    printf("|  Name  | Type| Nominal | Amount |\n");
    printf("|---------------------------------|\n");
    for(i=0; i<n; i++)
    {
        printf("|%8s|%5c|%9.1f|%8d|\n", mas[i].name, mas[i].type, mas[i].coast, mas[i].number);
        printf("|---------------------------------|\n");
    }
    //Сортировка
    for (i=0; i<n-1; i++)
    {
      m=i;
      for (j=i+1; j<n; j++)
        if (strcmp(mas[m].name, mas[j].name) > 0) m=j;
        if (m>i)
        {
          strcpy(x.name,mas[i].name);
          x.type=mas[i].type;
          x.coast=mas[i].coast;
          x.number=mas[i].number;
          strcpy(mas[i].name,mas[m].name);
          mas[i].type=mas[m].type;
          mas[i].coast=mas[m].coast; mas[i].number=mas[m].number;
          strcpy(mas[m].name,x.name); mas[m].type=x.type;
          mas[m].coast=x.coast; mas[m].number=x.number;
          }
    }
    printf("| Primechanie: R - resistor;      |\n");
    printf("|              C - capacitor.     |\n");
    printf(" ---------------------------------\n");

    printf(" \n ---------------------------------\n");
    printf("|    Vedomost' komplectuyushih    |\n");
    printf("|---------------------------------|\n");
    printf("|  Name  | Type| Nominal | Amount |\n");
    printf("|---------------------------------|\n");
    for(i=0; i<n; i++)
    {
        printf("|%8s|%5c|%9.1f|%8d|\n", mas[i].name, mas[i].type, mas[i].coast, mas[i].number);
        printf("|---------------------------------|\n");
    }
        printf("| Primechanie: R - resistor;      |\n");
    printf("|              C - capacitor.     |\n");
    printf(" ---------------------------------\n");




      return 0;
}

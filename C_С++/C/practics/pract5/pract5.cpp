//Классная №5
#include <stdio.h>
#include <cmath>
int main()
{
   int i,s;
   printf(" ------------\n");
   printf("|  n  |  2^n |\n");
   printf(" ------------\n");
   for(i=0;i<11;i++)
   {
        s=pow(2,i);
        printf("|%5d|%5d |\n",i,s);
        printf(" ------------\n");
   }
 return 0;
}

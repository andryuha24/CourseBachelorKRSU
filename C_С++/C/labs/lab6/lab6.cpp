#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));
    const int n = 100;
    int Ar[n];
    int tmp=0, i, j;
    for(i=0; i<n;i++)
    {
        Ar[i]=rand()%200-100;
        if(i%20==0) printf("\n");
        printf("%d ", Ar[i]);
    }

   for (int i=0; i<n; i++)
  {
    for (int j=0; j<(n-1); j++)
    {
      if (Ar[j] > Ar[j+1])
      {
        tmp = Ar[j];
        Ar[j] = Ar[j+1];
        Ar[j+1] = tmp;
      }
    }
  }
 printf("\nstroka otsortirovana: ");
    for( i=0; i < n; i++)
    {
     if(i%10==0) printf("\n");
     printf("%4d ", Ar[i]);
    }
      return 0;
}

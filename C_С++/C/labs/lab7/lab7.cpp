// Лаба Й7
#include <stdio.h>


int main()
{
 const int S=9;
 int Ar[S][S];

 short l, r, r1=1,r2=S-2, dd=1, k=1;

    for (r=0; r<S; r++)
    {
        for (l=0; l<S; l++)
          if ((l<r1)||(l>r2)) Ar[l][r]=0;
          else Ar[l][r]=k++;
        r1+=dd; r2-=dd;
        if (r1>r2) dd=-dd;
    }
    for (l=0; l<S; l++)
    {
        for (r=0; r<S; r++)
          printf("%3d",Ar[l][r]);
        printf("\n");
    }

  return 0;
}

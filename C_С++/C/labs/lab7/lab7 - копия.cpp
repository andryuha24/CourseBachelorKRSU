#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>
int main ()
{
srand(time(NULL));

int i,j, N=9;
int a[N][N];
printf ("Enter 9 elements of matrix :\n");
for (i=0; i<N; ++i)
{
for (j=0; j<N; ++j)
{
   a[i][j]=rand()%5+1;
    if ((i<=j)&&(i>=N-j-1)){
            a[i][j] = a[i][N-j-1];
     printf("%d ", a[i][j]);


}
printf("\n");
    }

for( i=0; i<N; i++)
                for(j=0; j<N; j++)
                {

                }

for (i=0; i<N; ++i)
 {
     for (j=0; j<N; ++j)

     printf("\n");
 }


                return 0;
}
}

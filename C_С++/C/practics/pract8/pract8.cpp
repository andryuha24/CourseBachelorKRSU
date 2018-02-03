#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  const int N=3;
  int a[]={1};
  srand(time(NULL));
  int mas[N][N], sum1=0, sum2=0, min, max, k, l;

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) mas[i][j]=rand()%9+1;

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++) printf("%2d", mas[i][j]);
    printf("\n");
  }

  //Суммы диагоналей.
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
     if(i==j) sum1+=mas[i][j];
     if(j==N-1-i) sum2+=mas[i][j];
    }
  }
  //Максимальный эелемент столбца, минимальный элемент строки
  min=mas[0][0];
  max=mas[0][0];
  k=0;
  l=0;
    for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
       if(mas[i][j]<min)
       {
         min = mas[i][j];
          k = i;
       }
       if(mas[i][j]>max)
       {
         max = mas[i][j];
         l = j;
       }
    }
  }

int b[10]={0};
for(int i=1;i<20;i+=3) printf("%d ",b[i%5]=i);

  printf("\n Summa elementov glavnoi diagonali sum1 = %d", sum1);
  printf("\n Summa elementov pobochnoi diagonali sum1 = %d", sum2);
 printf("\n Minimalnii element %d nahoditsya v stroke i = %d", min, k);
  printf("\n Maksimalnii element %d v stolbce j = %d", max, l);

  return 0;
}

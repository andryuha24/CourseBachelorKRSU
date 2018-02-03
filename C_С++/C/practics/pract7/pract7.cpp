#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void fill(int *p, int size)
{
  for ( int i=0; i<size; i++) p[i]=rand()%10+1;
}

void show(int *p, int size)
{
   for ( int i=0; i<size; i++)printf("%d ",p[i]);
}

int sum(int *p, int size)
{
    int sum=0;
    for ( int i=0; i<size; i++) sum+=p[i];
    return sum;
}


double sred(int *p, int size)
{
  return (double)sum(p,size)/size;
}

int max(int *p, int size)
{
  int max=p[0];
  for ( int i=0; i<size; i++) if(p[i] > max) max = p[i];
  return max;
}

int min(int *p, int size)
{
  int min=p[0];
  for ( int i=0; i<size; i++) if(p[i] < min) min = p[i];
  return min;
}

int chet(int *p, int size)
{
  int k = 0;
  for ( int i=0; i<size; i++) if(p[i]%2==0) k++;
  return k;
}

int main ()
{
    srand(time(NULL));
    const int n = 10;
    int maxM, minM, kM, sumM;
    double sredM;


    int mas[n];
    fill(mas, n);
    show(mas, n);

    sumM = sum(mas,n);
    printf("\nSumma elementov massiva sum = %d \n", sumM);

    sredM = sred(mas,n);
    printf("Srednee arifmeticheskoe elementov massiva sred = %.3lf \n", sredM);

    maxM = max(mas, n);
    printf("Maksimalnii  element massiva max= %d\n", maxM);

    minM = min(mas, n);
    printf("Maksimalnii  element massiva min= %d\n", minM);

    kM = chet(mas,n);
    printf("Kolichestvo chetnih elementov k= %d\n", kM);


  return 0;
}


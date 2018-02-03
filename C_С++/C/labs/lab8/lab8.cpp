#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));
    int size;

    size=rand()%150+50;
    printf("size = %d\n",size);
    int *Ar=new int[size];

    int tmp=0, i, j;
    for(int i=0; i<size;i++)
    {
        *(Ar+i)=rand()%200-100;
        if(i%20==0) printf("\n");
        printf("%d ", *(Ar+i));
    }

   for (int i=0; i<size; i++)
  {
    for (int j=0; j<(size-1); j++)
    {
      if (*(Ar+j) > *(Ar+j+1))
      {
        tmp = *(Ar+j);
        *(Ar+j) = *(Ar+j+1);
        *(Ar+j+1) = tmp;
      }
    }
  }
 printf("\nstroka otsortirovana: ");
    for(int i=0; i < size; i++)
    {
     if(i%10==0) printf("\n");
     printf("%4d ", *(Ar+i));
    }
    delete []Ar;
      return 0;
}

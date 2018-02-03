//Лаба №5

#include <stdio.h>
#include <math.h>


int main()
{
    //setlocale(LC_ALL, "Russian");
     const double eps = 0.000001;
    double sum = 0,  sum10=0, tmp = 1;
    int n = 0;
    long k1=1;
    long k2=1;
    while (fabs(tmp)>eps)
        {
            tmp=k1*k2/(pow(n,n+1)+1.);
            sum+=tmp;
            n++;
            k1=-k1;
            k2*=2;
        }
    printf("eps=%lf tmp =%.12lf n=%ld sum=%lf  ", eps,tmp, n,sum);

    for (n=0; n<10; n++)
    {
     tmp=k1*k2/(pow(n,n+1)+1.);
     sum10+=tmp;
     k1=-k1;
     k2*=2;
    }
    printf("\nSumma pervih chlenov ryada s = %lf", sum10);
    return 0;
}

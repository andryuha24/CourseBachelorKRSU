//Классная №5
#include <stdio.h>
#include <cmath>
int main()
{
    long int n=0;
    int k=1;
    double sum=0,eps, tmp=1, PI;
    printf("Vvedite Eps\n ");
   scanf ("%lf", &eps);
    while (fabs(tmp)>eps)
    {
        tmp=k/(2.*n+1);
        sum+=tmp;
        n++;
        k=-k;
    }

    PI=4*sum;
    printf("eps=%lf tmp =%lf n=%ld sum=%lf PI=%.10lf ", eps,tmp, n,sum, PI);
    return 0;
 return 0;
}

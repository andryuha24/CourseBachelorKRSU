//Ћабораторна€  є2
//(¬ариант є7)
#include <stdio.h>
#include <cmath>
#include <locale.h>
int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a = 0.1, b = 2.3;
    double t1, t2, x, kub, w1, c, c1, d,  k;

       printf("¬ведите x: ");
    scanf("%lf", &x);
    kub = a*a*a;
    w1 = 1/(2*a);
    c = b*b;
    c1 = a*x;
    d = b/x;
    k = tan(c1/2);
    if(x > 0){
        t1 = (1/kub)*(log(x)+2*d-(d*d/2));
        printf("\nt1 = (1/(a^3))*(ln(x) + 2b/x - (b^2)/2x^2) = %lf\n", t1);
    }
    else
        printf("¬ведены не верные данные!\n«начение аргумента X не входит в область допустимых значений.\n");

    if(x > 0 && k > 0){
        t2 = (w1)*(cos(c1)/(sin(c1)*sin(c1)))+(w1)*log(k);
        printf("\nt2 = (1/2a)*(cos(ax)/(sin(ax))^2) + (1/2a)*ln(tg(ax/2)) = %lf\n", t2);

    }
    else{
        printf("\n¬ведены не верные данные!\n«начение аргумента X не входит в область допустимых значений.\n");
    }
    return 0;
}

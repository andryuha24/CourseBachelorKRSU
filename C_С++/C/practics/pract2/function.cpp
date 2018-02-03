#include <stdio.h>
#include <math.h>

 main()
{
    const double PI = M_PI;
    double alfa, w, b, c, d, y, z;
    printf("PI + %lf\n",PI);
    printf("Input alfa: ");
    scanf("%lf", &alfa);

    alfa = alfa*180/PI;
    w = alfa/4;
    b = cos((3/8)*PI - w);
    c = cos((11/(8*PI))+ w);
    d = sin(alfa/2);
    y = b*b-c*c;
    z = (sqrt(2)/2)*d;

    printf("y = %g \n", y);
    printf("z = %g",z );

    return 0;
}

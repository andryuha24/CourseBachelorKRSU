#include <stdio.h>

int main(void)
{
    int grp, sys, p;
    unsigned short user;

    user = 0;
    grp = 201;
    sys = 3;
    p = 1;

    user |= (grp << 8) | (sys << 4) | (p << 3);

    printf("user: %hx\n", user);

    return 0;
}

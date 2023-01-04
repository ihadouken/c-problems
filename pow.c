#include <stdio.h>
/* demonstrates use of functions */

int power(int base, int n);

float expo(int base, int power);

int main()
{
    /*int i;*/

    /*printf("x  %3s  %6s\n", "2^x", "(-3)^x");*/
    /*for (i = 0; i < 10; ++i) {*/
        /*printf("%d  %.4f  %.4f\n", i, expo(2, i), expo(-3, i));*/
        /*printf("%d  %3d  %6d\n", i, power(2, i), power(-3, i));*/
    /*}*/

    printf("%.4f\n", expo(8, 4));
    return 0;
}

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

float expo(int base, int power)
{
    if (power == 0)
        return 1;
    else if (power < 0)
        return 1/expo(base, -power);

    else if ((power % 2) == 0) {
        float temp;
        temp = expo(base, power/2);
        return temp * temp;
    }

    else if ((power % 2) != 0)
        return base * expo(base, power-1);
    else return 0;
}

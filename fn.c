#include <stdio.h>
/* demonstrates use of functions */

int power(int base, int n);

int main()
{
    int i;

    printf("x  %3s  %6s\n", "2^x", "(-3)^x");
    for (i = 0; i < 10; ++i)
        printf("%d  %3d  %6d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n)
{
    int p;
    
    for (p = 1; n > 0; --n) 
        p = p * base;
    return p;
}

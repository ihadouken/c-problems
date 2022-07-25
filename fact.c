#include <stdio.h>
/* factorial implementations */

int iter_fact(int num);

int rec_fact(int num);

int main(void) {
    int n;
    n = 10;

    /*printf("%d\n", iter_fact(n));*/
    printf("%d\n", rec_fact(n));
    return 0;
}

int iter_fact(int num) {
    int fact;
    fact = 1;

    while (num >= 1) {
        fact *= num;
        num -= 1;
    }

    return fact;
}

int rec_fact(int num) {
    if (num == 0)
        return 1;
    else if (num > 0)
        return num * rec_fact(num-1);
    else
        return 0;
}

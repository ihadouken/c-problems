#include <stdio.h>
/* factorial implementations */

int iter_fact(int num);

int rec_fact(int num, int cache[]);

int main(void) {
    /* memoization */
    int cache[100] = {0};
    int n;
    n = 3;

    /*printf("%d\n", iter_fact(n));*/
    printf("%d\n", rec_fact(n, cache));

    n = 4;
    printf("%d\n", rec_fact(n, cache));
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

int rec_fact(int num, int cache[]) {
    if (num == 0)
        return 1;
    if (cache[num] != 0)
        return cache[num];
    else if (num > 0) {
        cache[num] = num * rec_fact(num-1, cache);
        return cache[num];
    }
    else
        return 0;
}

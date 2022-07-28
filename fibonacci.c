#include <stdio.h>
/* recursive function to calc. Nth term of fibonacci sequence (memoization) */

int fib(int n, int cache[]);

int main(void) {
    int cache[100] = {0};
    printf("%d\n", fib(6, cache));
    return 0;
}

int fib(int n, int cache[]) {
    if (n == 1 || n == 2)
        return n-1;
    else if (cache[n] != 0)
        return cache[n];
    else {
        cache[n] = fib(n-1, cache) + fib(n-2, cache);
        return cache[n];
    }
}

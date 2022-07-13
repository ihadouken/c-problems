#include <stdio.h>
/* calculate individual digits for a number and stores into array (helping madii) */

int main() {
    int num, len, i;
    int digits[10];
    num = 123456;
    len = 0;
    printf("number: %d\n", num);

    /* main loop that evaluates digits in reverse order */
    while (num != 0) {
        digits[len++] = num % 10;
        num = num / 10;
    }

    printf("digit count: %d\n\n", len);

    /* reverse order to original */
    for (i=0; i<len/2; ++i) {
        digits[i] = digits[i] + digits[len-1-i];
        digits[len-1-i] = digits[i] - digits[len-1-i];
        digits[i] = digits[i] - digits[len-1-i];
    } 
    
    /* printing of digits */
    printf("digits:\t");
    for (i=0; i<len-1; ++i) {
        printf("%d, ", digits[i]);
    }
    printf("%d\n", digits[len-1]);
    return 0;
}


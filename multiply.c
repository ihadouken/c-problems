#include <stdio.h>
/* multiplication of large numbers using array */
#define MAXDIGS 1024

void multiply(int *num, int len, int factor);
int main() {
    int len, i;
    int num[MAXDIGS] = {6, 6, 6};
    len = 3;

    /*int num[MAXDIGS];*/
    /*len = 300;*/
    /*for (i = 0; i < len; ++i)*/
        /*num[i] = i;*/

    multiply(num, len, 2);

    for (i = len; i >= 0; --i) {
        printf("%d", num[i]);
    }
    return 0;
}

void multiply(int *num, int len, int factor) {
    int i, carry, product;
    carry = 0;

    for (i = 0; i < len; ++i) {
        product = num[i] * factor + carry;
        num[i] = product % 10;
        carry = product / 10;
    }
    num[len] = carry;
}

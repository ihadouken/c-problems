#include <stdio.h>
/* checks ascii charset and displays numeric values for chars. */

int main() {
    int c;
    int val;
    
    printf("Please enter your character: ");
    c = getchar();

    printf("ASCII value for %c: %d\n", c, c);

    val = c - '0';
    printf("difference of %c with zero: %d\n", c, val);

    return 0;
}


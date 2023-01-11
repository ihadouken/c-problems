#include <stdio.h>
/* prints N rows of pascal's triangle */

/* function that prints 'n' rows of pascal's triangle */
void print_pascal(int n);

int main() {
    /* accept num. of rows to print */
    int n;
    printf("How many rows should I print ?\n");
    scanf("%d", &n);
    printf("%d ? ok.\n\n", n);

    print_pascal(n);
    return 0;
}

void print_pascal(int n) {
    /* vars:
     *      line -> current line num.
     *      j -> index of a num. in row
     *      ncr -> calculation of combination(n, r)
     *      width -> space to print a num. (formatting) */
    int line, j, ncr, width;

    /* set width acc. to num. of rows */
    width = n/4;

    for (line = 0; line < n; ++line) {
        /* first num. in every row is always 1 */
        ncr = 1;

        /* print spaces before the row (for symmetry) */
        for (j=0; j < n - line - 1; ++j)
            putchar(' ');

        /* print row */
        /* j not init. to 0 as it is used for computing the number for next iteration */
        for (j=1; j<=line+1; ++j) {
            /* print a space before num. (to make the triangle symmetrical) */
            putchar(' ');

            /* print the num. */
            printf("%*d", width, ncr);

            /* calculate the num. to print (using prev. num.) */
            ncr = ncr * (line - j + 1) / j;
        }

        /* end line after printing row */
        putchar('\n');
    }
}

#include <stdio.h>
#include <math.h>
/* receive a N*N binary matrix and print its
 * unique rows (madii's request) */

/* auxillary fumctions:
 *      1) bin2dec -> converts the binary number stored in array to decimal, returns decimal 
 *      2) prow -> prints the given row */

int bin2dec(int digits[], int length);
void prow(int row[], int length);

int main(int argc, char** argv) {
    /* vars:
     *      1) i,j -> loop indices
     *      2) total -> total number of elements
     *      2) order -> matrix order
     *      3) dec -> converted decimal value
     *      4) counter -> counts independantly from loop
     *      5) unique -> flag stating uniqueness of row*/

    if (argc != 2)
        return 255;

    int i, j, total, order, counter, dec, unique;

    /* find number of elements in given matrix */
    for (total=0; argv[1][total] != '\0'; ++total)
        ;
    printf("[DEBUG] Total elements: %d\n\n", total);

    /* find order */
    order = sqrt(total);

    /* arrays: 
     *     1) 2D array stores matrix
     *     2) stores decimal values of seen rows
    */
    int matrix[order][order];
    int decs[order];

    /* initialize your matrix */
    counter = 0;
    for (i=0; i<order && counter<total; ++i)
        for (j=0; j<order; ++j)
            matrix[i][j] = argv[1][counter++] - '0';
    
    /* selective print of rows */
    counter = 0;
    for (i=0; i<order; ++i) {
        /* convert matrix row (binary no.) to decimal */
        dec = bin2dec(matrix[i], order);
        /*printf("[DEBUG] Decimal conversion for row %d: %d\n", i, dec);*/
        unique = 1;

        /* converted number seen before ? */
        for (j=0; j<counter; ++j) {

            /* yes - then skip row */
            if (dec == decs[j]) {
                unique = 0;
                printf("[DEBUG] FOUND Duplicate: row %d\n", i);
                break;
            }
        }

        /* no - store decimal converion and print row*/
        if (unique) {
            decs[counter++] = dec;
            printf("[DEBUG] Printing row %d ...\n", i);
            prow(matrix[i], order);
        }
    }
    return 0;
}

void prow(int row[], int length) {
    int i;
    for (i=0; i<length; ++i)
        printf("%d ", row[i]);
    printf("\n");
}

int bin2dec(int digits[], int length) {
    int weight, dec, i;
    dec = 0;
    weight = 1;

    for (i=length-1; i>=0; --i) {
        dec += digits[i]*weight;
        weight *= 2;
    }
    return dec;
}

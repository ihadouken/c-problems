#include <stdio.h>
/* check if number is even or odd without using operator */

int str2int(char str[]);

int main(int argc, char** argv) {
    if (argc != 2)
        return 255;

    int num;
    num = str2int(argv[1]);

    /* for all even n, int (n+1)/2 will trunicate 
     * to n/2 
     * ex:- 4/2 = 5/2 */
    if (num/2 == (num+1)/2)
        return 1;

    /* for all odd n, int (n)/2 will trunicate to
     * (n-1)/2 and hence not equal to (n+1)/2
     * ex:- 7/2 = 8/2 */
    else
        return 0;
}

int str2int(char str[]) {
    int len, i, val;
    len = val = 0;
    /*int weight = 1;*/

    /* find no. of digits in numeric string */
    while (str[len] != '\0') {
        ++len;
    }

    /* multiply each digit with respective place-value (weight) and add all the products */
    /* uses horner's method */
    for (i=0; i<len; ++i) {
        val = val * 10 + (str[i] - '0');
    }

    /*for (j=len-1; j>=0; --j) {*/
        /*val += weight * (str[j] - '0');*/
        /*weight *= 10;*/
    /*}*/
    return val;
}

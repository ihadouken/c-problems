#include <stdio.h>
#include <string.h>
/* implements luhn's algorithm to examine the validity of identification numbers (recommended by madii)*/

int main(int argc, char** argv) {
    /* do not proceed if:
     *   1) there is no number given
     *   2) there are more than one arguments*/
    if (argc != 2)
        return 254;

    /* copy the argumented numbers into
     * the numbers buffer*/
    char num[100];
    strcpy(num, argv[1]);

    int i, j, val, sum;
    sum = 0;

    /* find length of given number and validate input */
    for (i=0; num[i]!='\0'; i++)
        if (!(num[i] >= '0' && num[i] <= '9'))
            return 255;

    printf("[DEBUG] Input: %s Length: %d\n" , num, i);

    /* process every second digit from last */
    for (j=i-2; j>=0; j-=2) {
        /* double every number */
        val = 2*(num[j]-'0');

        /* round two digit number to one */
        if (val>9)
            val = val-9;

        num[j] = '0' + val;
    }

    printf("[DEBUG] New number: %s\n", num);

    /* compute checksum */
    for (j=0; j<i; ++j)
        sum += num[j] - '0';

    printf("[DEBUG] Checksum: %d\n", sum);
    
    /* invalid (indivisible by 10)*/
    if (sum%10)
        return 1;
    /* valid */
    else
        return 0;
}

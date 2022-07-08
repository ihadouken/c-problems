#include <stdio.h>
#define MAXDIGS 22
/* full adder fumction (recommended by madii) */

/* The Workhorse:
 *      accepts two binary strings i.e augend, addend
 *      returns a pointer to first elemenrs of augend */
char * addBinary(char augend[], char addend[]);

int main(int argc, char** argv) {
    if (argc != 3)
        return 255;
    
    printf("Input: %s %s\n", argv[1], argv[2]);
    char *ptr = addBinary(argv[1], argv[2]);
    printf("Output: %s\n", ptr);
    return 0;
}

char * addBinary(char augend[], char addend[]) {
    /* vars:
     *      1) i -> loop counter
     *      2) len -> no. of digits in binary
     *      3) carry -> stores carry bit
     *      4) lead_zero -> number of leading zeroes in addition output */
    int i, len, lead_zero;
    lead_zero = 0;
    char carry;
    carry = '0';

    /* find length of binary numbers */
    for (len=0; augend[len]!='\0'; ++len)
        ;

    for (i=len-1; i>=0; --i) {
        /* bits to be added same */
        if (augend[i] == addend[i]) {
            /* 1+1+1 = 11 , 0+0+1 = 01 , 1+1+0 = 10 , 0+0+0 = 00 i.e sum equal to input carry*/
            augend[i] = carry;

            /* output carry equal to previous value (preserved in addend string) */
            carry = addend[i];
        }
        
        /* bits inequal */
        else {
            /* sum is opposite to input carry which itself propagates */
            /* 1+0+1 = 10 , 0+1+1 = 10 */
            if (carry == '1')
                augend[i] = '0';
            /* 1+0+0 = 01 , 0+1+0 = 01 */
            else
                augend[i] = '1';
        }
    }
    
    /* carry after adding MSBs */
    if (carry == '1') {
        /* shift all digits to right (including null) */
        ++len;
        for (i=len-1; i>=0; --i) {
            augend[i] = augend[i-1];
        }
        /* Store carry as MSB */
        augend[0] = carry;
    }

    /* find out number of leading zeroes */
    while (augend[lead_zero] == '0') {
        ++lead_zero;
    }

    /* shift string to left (including null) to eliminate leading zeroes */
    for (i=lead_zero; i<=len ; ++i) {
        augend[i-lead_zero] = augend[i];
    }

    /* return pointer to first character of string */
    return augend;
}

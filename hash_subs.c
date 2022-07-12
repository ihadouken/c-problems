#include <stdio.h>
#define MAXCHAR 128
/* prepares a list of substrings of a string of given length and computes hash for each (recommended by madii) */

/* hash -> outputs hash for string of given length
 * str2int -> converts numeric strings to integers*/
int hash(char key[], int len);
int str2int(char str[]);

int main(int argc, char** argv) {
    if (argc != 3)
        return 255;

    /* sublen -> length of substrings
     * num_subs -> no. of substrings of 'sublen' possible for a string (computed by formula below)*/
    int i, j, len, sublen, num_subs;
    char str[MAXCHAR];
    len = 0;
    /* copy cmd-line string to buffer and computed length*/
    while ((str[len] = argv[1][len]) != '\0')
        ++len;
    
    sublen = str2int(argv[2]);
    num_subs = len - sublen + 1;
    
    /* matrix to store substrings */
    char substrs[num_subs][sublen+1];
    
    /* creating substrings */
    for (i=0; i<num_subs; ++i) {
        for (j=0; j<sublen; ++j)
            substrs[i][j] = str[i+j];
        substrs[i][j] = '\0';
    }
    
    /* print hash for every substring */
    for (i=0; i<num_subs; ++i) {
        printf("%d) %s -> %d\n", i+1, substrs[i], hash(substrs[i], sublen));
    }
    return 0;
}

int hash(char key[], int len) {
    int i, base, mod, hash;
    base = 31;
    mod = 1e9 + 9;
    hash = 0;
    /*long exp = 1;*/
    
    for (i=0; i<len; ++i) {
        /* uses horner's method */
        hash = (hash * base + (key[i] - 'a')) % mod;

        /*hash = (hash + (key[i] - 'a' + 1) * exp) % mod;*/
        /*exp = (exp * base) % mod ;*/
    }

    return hash;
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

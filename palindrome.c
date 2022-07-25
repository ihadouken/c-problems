#include <stdio.h>
/* checks if a string is same if spelled backwards
 * ex:- rotor */

int pcheck(char str[], int start, int stop);

int main(int argc, char** argv) {
    if (argc != 2)
        return 255;

    int len, is_pdrome;

    len = 0;
    while (argv[1][len] != '\0')
        ++len;

    is_pdrome = pcheck(argv[1], 0, len-1);

    if (is_pdrome)
        printf("Palindrome \"%s\" spotted\n", argv[1]);
    else
        printf("No, \"%s\" is not a palindrome sire\n", argv[1]);

    return 0;
}


int pcheck(char str[], int start, int stop) {
    if (start == 0 && stop == 0) {
        printf("they both zero\n");
        return 1;
    }
    else if (stop < start)
        return 1;
    else if (str[start] == str[stop]) {
        return pcheck(str, start+1, stop-1);
    }
    else
        return 0;
}

#include <stdio.h>
#include <string.h>
/* finds the largest palindromic substring in a given string */

char * max_pdrome(char *str);
int grow_pdrome(char *str, int len, int *ptr1, int *ptr2);

int main(void) {
    /* not passing input string 'literally' to
     * max_pdrome as it trunicates the overwriting
     * a character with null which produces segfault
     * as the 'literal' string is read-only */
    char input[] = "dgtyracecargihj";
    char *pdrome = max_pdrome(input);

    printf("Output: %s\n", pdrome);
    return 0;
}

char * max_pdrome(char *str) {
    int beg, end, slen, p1, p2, i, curlen, pdrome_len;

    beg = end = 0;
    pdrome_len = 1;
    slen = strlen(str);

    for (i = 1; i < slen-1; ++i) {

        p1 = p2 = i;
        if ((curlen = grow_pdrome(str, slen, &p1, &p2)) > pdrome_len) {
            beg = p1;
            end = p2;
            pdrome_len = curlen;
        }

        p1 = i;
        p2 = i + 1;
        if ((curlen = grow_pdrome(str, slen, &p1, &p2)) > pdrome_len) {
            beg = p1;
            end = p2;
            pdrome_len = curlen;
        }

        if (pdrome_len == slen)
            break;
    }

    str[end+1] = '\0';
    return &str[beg];
}

int grow_pdrome(char *str, int len, int *ptr1, int *ptr2) {
    while (*ptr1 > 0 && *ptr2 < len) {
        if (str[*ptr1 - 1] == str[*ptr2 + 1]) {
            *ptr1 = *ptr1 - 1;
            *ptr2 = *ptr2 + 1;
        }
        else
            break;
    }
    return *ptr2 - *ptr1 + 1;
}

#include <stdio.h>
/* removes all occurences of a given substring from a string */

void rm_subs(char str[], char substr[]);
int len(char string[]);

int main(void) {
    char line[] = "hlo hi";
    char word[] = "hi";
    printf("Before: %s\n", line);

    rm_subs(line, word);
    printf("Removed all \"%s\"\n\n", word);
    printf("After: %s\n", line);
    return 0;
}

void rm_subs(char str[], char substr[]) {
    /* subptr: record index of potential substring in str */
    int strlen, sublen, subptr, i, j;
    strlen = len(str);
    sublen = len(substr);

    subptr = 0;

    /* process all string even '\0' so substring at end of string also removed */
    for (i = 0; i <= strlen; ++i) {

        /* if last iteration ends up finding substring */
        if (subptr == sublen) {
            /* remove it by shifting the following characters towards left */
            for (j = i; j <= strlen; ++j)
                /* by displacing elements by 'sublen' towards left */
                str[j-sublen] = str[j];

            /* reset subptr for more occurences */
            subptr = 0;
        }

        /* if a part of string matching with
         * part of substring */
        if (str[i] == substr[subptr])
            ++subptr;

        /* if the part of string stops matching with the substring, reset subptr */
        else
            subptr = 0;
    }
}

int len(char string[]) {
    int length = 0;

    while (string[length] != '\0')
        ++length;

    return length;
}

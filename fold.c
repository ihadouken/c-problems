#include <stdio.h>
/* folds a long line into smaller lines at the last blank character
 * before a farthest permitted column */

int get_blank(char line[], int len);

#define MAXCOL 8
#define NO_BLANK -1
#define TABSPC 4
 
int main() {
    int pos, col, c, i, j, blank;
    char line[MAXCOL];

    pos = col = 0;
    while ((c=getchar()) != EOF) {
        if (c == ' ' && pos == 0)
            continue;

        line[pos++] = c;
        col++;

        if (col >= MAXCOL || c == '\n') {
            blank = get_blank(line, pos);

            if (blank == NO_BLANK) {
                for (i=0; i<pos; ++i)
                    putchar(line[i]);
                col = pos = 0;
            }

            else {
                for (i=0; i<blank; ++i)
                    putchar(line[i]);

                for (i=0, j=blank+1, col=0; j<pos; ++i, ++col, ++j)
                    line[i] = line[j];
                pos = i;
            }
            putchar('\n');
        }
    }

    return 0;
}

int get_blank(char line[], int len) {
    int blankpos;
    blankpos = len-1;

    while (blankpos > 0) {
        if (line[blankpos] == ' ' || line[blankpos] == '\t' || line[blankpos] == '\n')
            return blankpos;
        --blankpos;
    }

    return NO_BLANK;
}

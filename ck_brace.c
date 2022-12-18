#include <stdio.h>
/* check if all braces are properly closed */
#define OPENING '{'
#define CLOSING '}'

int main(void) {
    int ch, count;
    ch = count = 0;

    while((ch=getchar()) != EOF) {
        if (ch == OPENING)
            ++count;
        else if(ch == CLOSING)
            --count;
    }

    if (count == 0)
        return 0;
    else
        return 1;

    return 0;
}


#include <stdio.h>

int main() {
    int c, i;
    printf("Enter a character.\n");
    c = getchar();
    printf("Input character: %c\n", c);
    
    char name[5] = {'h', 'k', 'e', 'n'};
    printf("Printing your name ...\n");

    for (i=0; i<5; i++) 
        putchar(name[i]);

    return 0;
}

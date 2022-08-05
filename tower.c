#include <stdio.h>
#include <math.h>
/* tower of hanoi */

#define BEG 'A'
#define AUX 'B'
#define END 'C'

void toh(int disk_num, char from, char to, char extra);
void toh_iter(int ndisks, char from, char to, char extra);

int main() {
    int n;
    n = 3;
    
    /*toh(n, BEG, END, AUX);*/
    toh_iter(n, BEG, END, AUX);
    return 0;
}

void toh_iter(int ndisks, char from, char to, char extra) {
    int nmoves, i;
    nmoves = pow(2, ndisks) - 1;

    if ((ndisks % 2) != 0) {
        to = to + extra;
        extra = to - extra;
        to = to - extra;
    }

    for (i = 1; i <= nmoves; ++i) {
        if ((i % 2) == 0)
            printf("%c -> %c\n", from, to);
        else if ((i % 2) == 1)
            printf("%c -> %c\n", from, extra);
        else if ((i % 2) == 2)
            printf("%c -> %c\n", to, extra);
    }
}

void toh(int disk_num, char from, char to, char extra) {
    if (disk_num == 0)
        return;
    else {
        toh(disk_num - 1, from, extra, to);
        printf("moving disk %d: %c -> %c\n", disk_num, from, to);
        toh(disk_num - 1, extra, to, from);
    }
}

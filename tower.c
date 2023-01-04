/* towers of hanoi iterative and recursive implementations */

/* defined to use posix functions with c99 standard */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define BEG 'A'
#define AUX 'B'
#define END 'C'

void toh(int disk_num, char from, char to, char extra);
void toh_iter(int ndisks, char from, char to, char extra);

int main(int argc, char *argv[]) {
    int n = 0;
    int ch;

    /* the following line disables automatic argument errors by getopt */
    /*opterr = 0;*/

    while ((ch = getopt(argc, argv, "n:")) != EOF) {
        switch (ch) {
            case 'n':
                n = *optarg - '0';
                break;
            /*case '?':*/
                /*if (optopt == 'n')*/
                    /*fprintf(stderr, "The option '%c' requires an argument\n", optopt);*/
                /*return 1;*/
            /*default:*/
                /*fprintf(stderr, "Unknown option: '%c'\n", optopt);*/
                /*return 1;*/
        }
    }

    argc -= optind;
    argv += optind;

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

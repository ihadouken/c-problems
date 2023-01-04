#include <stdio.h>
/* finds players that lost no or exactly 1 match */

void find_winners(int matches[100000][2], int msize, int stats[2][100000], int *stats_col_sizes) {
    int loses[100000], i, loser, winner;

    for (i = 0; i < msize; ++i) {
        loser = matches[i][1];
        loses[loser]++;
    }

    for (i = 0; i < msize; ++i) {
        winner = matches[i][0];
        loser = matches[i][1];

        if (loses[winner] == 0) {
            stats[0][stats_col_sizes[0]++] = winner;
            loses[winner] = -1;
        }

        if (loses[loser] == 1) {
            stats[1][stats_col_sizes[1]++] = loser;
            loses[loser] = -1;
        }
    }
}

int main(void) {
    int matches[][2] = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    int size = sizeof(matches)/sizeof(matches[0]);

    int res[2][100000];
    int res_col_sizes[2] = {0};
    find_winners(matches, size, res, res_col_sizes);

    int i;
    printf("Players who didn't lose:  ");
    for (i = 0; i < res_col_sizes[0]; ++i)
        printf("%d, ", res[0][i]);
    printf("\n");

    printf("Players who lost once:  ");
    for (i = 0; i < res_col_sizes[1]; ++i)
        printf("%d, ", res[1][i]);
    printf("\n");

    return 0;
}


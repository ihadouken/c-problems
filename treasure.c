#include <stdio.h>
/* my take on the treasure hunt problem */

void parse_clue(int row, int column, int clue, int next_pos[]);

int main() {
    int finding, column, row;
    int next[2];

    int mat[5][5] = {
        {34, 21, 32, 41, 25},
        {14, 42, 43, 14, 31},
        {54, 45, 52, 42, 23},
        {33, 15, 51, 31, 35},
        {21, 52, 33, 13, 23}
    };

    finding = 1;
    column = row = 0;

    while (finding) {
        parse_clue(row, column, mat[row][column], next);

        if (next[0] == -1)
            finding = 0;
        else {
            printf("In at (%d, %d). Jumping off to (%d, %d)\n", row + 1, column + 1, next[1] + 1, next[0] + 1);
            row = next[1];
            column = next[0];
        }
    }

    printf("Found treasure %d at (%d, %d) !!\n", mat[row][column], row + 1, column + 1);
    return 0;
}

void parse_clue(int row, int column, int clue, int next_pos[]) {
    int ones, tens;

    ones = clue % 10;
    tens = clue / 10;

    if (row == tens-1 && column == ones-1)
        next_pos[0] = next_pos[1] = -1;
    else {
        next_pos[0] = ones - 1;
        next_pos[1] = tens - 1;
    }
}

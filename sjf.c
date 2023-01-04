#include<stdio.h>
#define sorted 1
#define unsorted 0

int main()
{
    int i, j, n, state;
    printf("Enter no. of processes: \n");
    scanf("%d", &n);

    int bt[n];
    char pids[n];
    int waits[n];
    int turns[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter process id: \n");
        scanf(" %c", &pids[i]);

        printf("Enter burst times: \n");
        scanf("%d", &bt[i]);
    }

    printf("\n\nINPUT: \nPID\tBurts\n");
    for (i = 0; i < n; i++) {
        printf("%c\t%d\n", pids[i], bt[i]);
    }

    for (i = 0; i < n; i++) {
        state = sorted;
        for (j = 0; j < n-(i+1); j++) {
            if (bt[j] > bt[j+1]) {
                state = unsorted;

                bt[j] = bt[j] + bt[j+1];
                bt[j+1] = bt[j] - bt[j+1];
                bt[j] = bt[j] - bt[j+1];


                pids[j] = pids[j] + pids[j+1];
                pids[j+1] = pids[j] - pids[j+1];
                pids[j] = pids[j] - pids[j+1];
            }
        }

        if (state == sorted)
            break;
    }
    for (i = 0; i < n; i++) {
        if (i == 0) {
            waits[i] = 0;
            turns[i] = bt[0];
        }
        else {
            waits[i] = waits[i-1] + bt[i-1];
            turns[i] = waits[i] + bt[i];
        }
    }

    printf("\n\nOUTPUT: \nPID\tBurts\tWaits\tTurns\n");
    for (i = 0; i < n; i++) {
        printf("%c\t%d\t%d\t%d\n", pids[i], bt[i], waits[i], turns[i]);
    }
}

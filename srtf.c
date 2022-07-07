#include <stdio.h>

void prep_avail(void); 
int main(void) {
    int n, running, waits[], turns[], bt[], avail_bt[], avail_pids[];
    char pids[];

    printf("\nNo. of processes ?\n");
    scanf("%d", &n);

    for (i=0; i<n; ++i) {
        printf("\nEnter process id: ");
        scanf(" %c", &pids[i]);

        printf("\nEnter burst time: ");
        scanf("%d", &bt[i]);


        printf("\nEnter arrival time: ");
        scanf("%d", &arr[i]);
        for (i=0; i<n; ++i) {
            bt[i] = dbt[i];
        }

        running = 1;
        ptr = 0;
        while (running) {
            for (i=0; i<n; ++i) {
                if (arr[i] >= time) {
                    avail[ptr++] = pids[i];
                }
            }
            for (i=0; i<ptr; ++i) {
                for (j=0; i<n; ++i) {
                    if (avail[i] == pids[j]) {
                        dbt[j]
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

int select(char bt[], char pids[], char arr[]) {
    for (i=0; i<n; ++i) {
    }
}

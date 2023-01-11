#include <stdio.h>
/* implements bubble sort algorithm in c */

int main() {
    int i, j, len;

    int nums[8] = { 85, 38, 66, 78, 23, 76, 12, 43 };
    len = sizeof(nums)/sizeof(nums[0]);

    int unsorted;
    for (i = 0; i < len; ++i) {
        unsorted = 0;

        for (j = 0; j < len-(i+1); ++j) {
            if (nums[j] > nums[j+1]) {
                printf("Interchanging %d with %d\n", nums[j], nums[j+1]);
                nums[j] = nums[j] + nums[j+1];
                nums[j+1] = nums[j] - nums[j+1];
                nums[j] = nums[j] - nums[j+1];
                unsorted = 1;
            }
        }

        if (!unsorted)
            break;
    }

    printf("Elements: ");
    for (i = 0; i < len; ++i) {
        printf("%d ", nums[i]);
    }
    putchar('\n');
    return 0;
}

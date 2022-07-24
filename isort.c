#include <stdio.h>
/* insertion sort algorithm */

void isort(int arr[], int size);

int main(void) {
    int size, i;
    int nums[] = {15, 14, 4, 2, 8, 21, 9, 18, 19};
    size = sizeof(nums)/sizeof(nums[0]);

    isort(nums, size);

    for (i = 0; i < size; ++i)
        printf(" %d,", nums[i]);
    printf("\n");

    return 0;
}


void isort(int arr[], int size) {
    int key, i, j;

    /* start from 2nd element as list with
     * one element always sorted */
    for (i = 1; i < size; ++i) {

        /* save value of element to be sorted */
        key = arr[i];
        
        /* starting from element to left of key
         * upto first element */
        for (j = i-1; j >= 0; --j) {

            /* move element to right if its larger
             * than key to make room for it*/
            if (key < arr[j])
                arr[j+1] = arr[j];

            /* stop when an element is smaller */
            else 
                break;
        }

        /* put key in the vacated space */
        arr[j+1] = key;
    }
}

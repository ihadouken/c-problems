/* Find the location of a given element in a sorted array using binary search.
 * If the search fails, find an appropriate location for the element if it
 * were to be added to the array.*/


#include <stdio.h>

int bsearch(int arr[], int size, int target);

int main() {
    int len, loc;
    int nums[] = {0, 1, 3, 5, 7, 9, 11};

    len = sizeof(nums)/sizeof(nums[0]);
    loc = bsearch(nums, len, 8);
    printf("Result: %d\n", loc);
    return 0;
}

int bsearch(int arr[], int size, int target) {
    int beg, end, mid;
    beg = 0;
    end = size - 1;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }

    return beg;
}

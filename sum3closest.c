#include <stdio.h>
#include <stdlib.h>
/* finds a triplet whose sum is closest to a given target number in the given array */

int closest_triplet_sum(int* arr, int len, int target);
int closest_duet_sum(int* arr, int len, int target);
unsigned int abs_val(int val);
int cmpfunc (const void * a, const void * b);

int main(void) {
    int result, nums[] = {5, 12, -9, 43, 2, -65, 3, 4, 19, 23, -11};

    result = closest_triplet_sum(nums, sizeof(nums)/sizeof(nums[0]), 40);
    printf("Closest sum: %d\n", result);
    return 0;
}

int closest_triplet_sum(int* arr, int len, int target) {
    qsort(arr, len, sizeof(int), cmpfunc);

    int i, closest, found_sum;
    closest = arr[0] + arr[1] + arr[2];

    for (i = 0; i < len - 2; ++i) {
        found_sum = closest_duet_sum(arr + (i+1), len - (i+1), target - arr[i]) + arr[i];
    
        if (abs_val(closest - target) > abs_val(found_sum - target))
            closest = found_sum;
        
        if (closest == target)
            break;
    }
    return closest;
}

unsigned int abs_val(int val) {
    if (val < 0)
        return val * -1;
    else
        return val;
}

int closest_duet_sum(int* arr, int len, int target) {
    int p1, p2, sum;
    p1 = 0;
    p2 = len - 1;

    while ((p1 != p2) && ((sum = arr[p1] + arr[p2]) != target)) {
        if (sum < target)
            p1 += 1;
        else if (sum > target)
            p2 -= 1;
    }
    return sum;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

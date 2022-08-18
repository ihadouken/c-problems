#include <stdio.h>
/* demonstrates two pointer technique to find a sum in array */

void find_sum(int* arr, int target, int* ptr1, int* ptr2);

int main(void) {
    int p1, p2, len;
    int nums[] = {10, 20, 35, 50, 75, 80};

    len = sizeof(nums)/sizeof(nums[0]);
    p1 = 0;
    p2 = len - 1;
    
    find_sum(nums, 70, &p1, &p2);

    if (p1 == -1 && p2 == -1)
        puts("Sorry, target sum not found :(");
    else
        fprintf(stdout, "Power couple: %d and %d\n", p1, p2);
    return 0;
}

void find_sum(int* arr, int target, int* ptr1, int* ptr2) {
    int sum;

    while ((sum = arr[*ptr1] + arr[*ptr2]) != target) {
        if (sum < target)
            *ptr1 += 1;
        else if (sum > target)
            *ptr2 -= 1;
        
        if (*ptr1 == *ptr2) {
            *ptr1 = *ptr2 = -1;
            break;
        }
    }
}

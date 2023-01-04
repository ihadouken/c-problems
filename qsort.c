#include <stdio.h>
/* quick sort */

void quick_sort(int arr[], int beg, int end);
int divide(int arr[], int beg, int end);

int main(void) {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int i, len = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr, 0, len-1);

    for (i = 0; i < len; ++i)
        printf(" %d,", arr[i]);
    return 0;
}

void quick_sort(int arr[], int beg, int end) {
    if (beg >= end)
        return;
    else {
        int pivot;
        pivot = divide(arr, beg, end);

        quick_sort(arr, beg, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}

int divide(int arr[], int beg, int end) {
    int pivot, i, j, temp;
    pivot = arr[end];
    i = j = beg;

    while (j < end) {
        if (arr[j] > pivot)
            ;
        else {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            ++i;
        }
        ++j;
    }

    temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;

    return i;
}

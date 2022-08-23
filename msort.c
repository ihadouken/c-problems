#include <stdio.h>
/* merge sort */

void merge_sort(int arr[], int beg, int end);
void merge(int arr[], int beg, int mid, int end);

int main(void) {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int i, len = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, len-1);
    
    for (i = 0; i < len; ++i)
        printf(" %d,", arr[i]);
    return 0;
}

void merge_sort(int arr[], int beg, int end) {
    if (beg >= end)
        return;
    else {
        int mid;
        mid = (beg + end)/2;

        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);

        merge(arr, beg, mid, end);
    }
}

void merge(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int left[n1], right[n2], i, j, k;
    
    for (i = 0; i < n1; ++i)
        left[i] = arr[beg + i];

    for (j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    i = j = 0;
    k = beg;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    while (i < n1)
        arr[k++] = left[i++];
    
    while (j < n2)
        arr[k++] = right[j++];
}

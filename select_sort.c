#include <stdio.h>
/* selection sort algorithm */

void select_sort(int arr[], int size);

int main(void) {
    int n, i;
    
    int arr[] = { 15, 4, 2, 8, 79, 14, 6, 0 };
    n = sizeof(arr)/sizeof(arr[0]);

    select_sort(arr, n);

    for (i=0; i<n; ++i)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}

void select_sort(int arr[], int size) {
    int min, i, j, temp;
    for (i=0; i<size; ++i) {
        min = i;

        for (j=i+1; j<size; ++j) {
            if (arr[min] > arr[j])
                min = j;
        }
        
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

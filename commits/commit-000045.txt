/*
 * Program 45: Remove Duplicates from Sorted Array
 * Topic: Two Pointers
 */
#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) arr[j++] = arr[i];
    }
    arr[j++] = arr[n - 1];
    return j;
}

int main(void) {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int new_len = removeDuplicates(arr, 8);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < new_len; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

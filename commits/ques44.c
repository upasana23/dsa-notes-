/*
 * Program 44: Check if an Array is Sorted
 * Topic: Array Verification
 */
#include <stdio.h>
#include <stdbool.h>

bool isSorted(const int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main(void) {
    int arr1[] = {10, 20, 30, 40};
    int arr2[] = {10, 30, 20, 50};

    printf("arr1 sorted? %s\n", isSorted(arr1, 4) ? "Yes" : "No");
    printf("arr2 sorted? %s\n", isSorted(arr2, 4) ? "Yes" : "No");
    return 0;
}

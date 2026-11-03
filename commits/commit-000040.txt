/*
 * Program 40: Linear Search in an Array
 * Topic: Searching Algorithms
 */
#include <stdio.h>

int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main(void) {
    int arr[] = {15, 23, 7, 42, 88};
    int target = 42;
    int idx = linearSearch(arr, 5, target);

    if (idx != -1)
        printf("Element %d found at index %d.\n", target, idx);
    else
        printf("Element not found.\n");
    return 0;
}

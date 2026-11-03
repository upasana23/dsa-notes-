/*
 * Program 38: Find Minimum and Maximum in an Array
 * Topic: Array Traversal
 */
#include <stdio.h>

int main(void) {
    int arr[] = {23, 5, 89, -4, 56, 102, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Minimum: %d, Maximum: %d\n", min, max);
    return 0;
}

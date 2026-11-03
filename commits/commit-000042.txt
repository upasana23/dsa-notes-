/*
 * Program 42: Find Second Largest Element in Array
 * Topic: Array Traversal
 */
#include <stdio.h>
#include <limits.h>

int findSecondLargest(const int arr[], int n) {
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

int main(void) {
    int arr[] = {12, 35, 1, 10, 34, 1};
    printf("Second largest: %d\n", findSecondLargest(arr, 6));
    return 0;
}

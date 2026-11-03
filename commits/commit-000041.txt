/*
 * Program 41: Binary Search (Iterative)
 * Topic: Divide and Conquer
 */
#include <stdio.h>

int binarySearch(const int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int sorted[] = {10, 20, 30, 40, 50, 60, 70};
    int res = binarySearch(sorted, 7, 50);
    printf("Target found at index: %d\n", res);
    return 0;
}

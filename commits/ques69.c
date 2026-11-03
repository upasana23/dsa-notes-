/*
 * Program 69: Recursive Binary Search
 * Topic: Recursive Divide & Conquer
 */
#include <stdio.h>

int recBinarySearch(const int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;

    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return recBinarySearch(arr, low, mid - 1, key);
    return recBinarySearch(arr, mid + 1, high, key);
}

int main(void) {
    int arr[] = {3, 9, 14, 19, 25, 31, 42};
    int res = recBinarySearch(arr, 0, 6, 25);
    printf("Element index: %d\n", res);
    return 0;
}

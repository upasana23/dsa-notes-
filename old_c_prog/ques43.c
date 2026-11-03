/*
 * Program 43: Count Frequency of Elements in Array
 * Topic: Frequency Counting
 */
#include <stdio.h>

int countOccurrences(const int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) count++;
    }
    return count;
}

int main(void) {
    int arr[] = {2, 3, 2, 5, 2, 8, 2};
    printf("Count of 2: %d\n", countOccurrences(arr, 7, 2));
    return 0;
}

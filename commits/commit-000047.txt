/*
 * Program 47: Rotate Array Left by K Positions
 * Topic: Array Reversal Algorithm
 */
#include <stdio.h>

void reverse(int arr[], int l, int r) {
    while (l < r) {
        int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
        l++; r--;
    }
}

void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    rotateLeft(arr, 7, 2);
    for (int i = 0; i < 7; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

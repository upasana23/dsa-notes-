/*
 * Program 46: Merge Two Sorted Arrays
 * Topic: Merge Step
 */
#include <stdio.h>

void mergeSorted(const int a[], int n, const int b[], int m, int out[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) out[k++] = a[i++];
        else out[k++] = b[j++];
    }
    while (i < n) out[k++] = a[i++];
    while (j < m) out[k++] = b[j++];
}

int main(void) {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};
    int merged[8];

    mergeSorted(a, 4, b, 4, merged);
    for (int i = 0; i < 8; i++) printf("%d ", merged[i]);
    printf("\n");
    return 0;
}

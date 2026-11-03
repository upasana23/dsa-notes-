/*
 * Program 73: Dynamic Memory Allocation Using malloc()
 * Topic: Heap Memory & Memory Safety
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr); // Prevent memory leak
    return 0;
}

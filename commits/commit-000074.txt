/*
 * Program 74: Dynamic Reallocation Using calloc() and realloc()
 * Topic: Heap Resizing
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* arr = (int*)calloc(3, sizeof(int));
    if (!arr) return 1;

    arr[0] = 1; arr[1] = 2; arr[2] = 3;

    int* temp = (int*)realloc(arr, 5 * sizeof(int));
    if (!temp) {
        free(arr);
        return 1;
    }
    arr = temp;
    arr[3] = 4; arr[4] = 5;

    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

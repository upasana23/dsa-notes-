/*
 * Program 72: Pointer Arithmetic on Arrays
 * Topic: Pointer Increments & Offsets
 */
#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // points to arr[0]

    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d at address %p\n", i, *(ptr + i), (void*)(ptr + i));
    }
    return 0;
}

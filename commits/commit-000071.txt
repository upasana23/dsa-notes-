/*
 * Program 71: Swap Two Variables Using Pointers
 * Topic: Pass-by-Reference in C
 */
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 100, y = 200;
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}

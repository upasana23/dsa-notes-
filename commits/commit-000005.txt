/*
 * Program 05: Swap Two Numbers Without a Temporary Variable
 * Topic: Bitwise XOR Swap
 */
#include <stdio.h>

int main(void) {
    int a = 25, b = 75;
    printf("Before: a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After: a = %d, b = %d\n", a, b);
    return 0;
}

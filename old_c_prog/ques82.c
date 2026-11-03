/*
 * Program 82: Bitwise Operators Demo
 * Topic: Low-level Bitwise Manipulation
 */
#include <stdio.h>

int main(void) {
    int a = 12; // 00001100
    int b = 25; // 00011001

    printf("a & b: %d\n", a & b);
    printf("a | b: %d\n", a | b);
    printf("a ^ b: %d\n", a ^ b);
    printf("~a:    %d\n", ~a);
    printf("a << 1:%d\n", a << 1);
    printf("a >> 1:%d\n", a >> 1);
    return 0;
}

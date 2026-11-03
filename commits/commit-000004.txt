/*
 * Program 04: Swap Two Numbers Using a Temporary Variable
 * Topic: Variable Manipulation
 */
#include <stdio.h>

int main(void) {
    int x = 10, y = 20, temp;
    printf("Before swap: x = %d, y = %d\n", x, y);

    temp = x;
    x = y;
    y = temp;

    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}

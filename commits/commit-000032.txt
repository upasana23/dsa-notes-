/*
 * Program 32: Pyramid Star Pattern
 * Topic: Nested Loops & Spacing
 */
#include <stdio.h>

int main(void) {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

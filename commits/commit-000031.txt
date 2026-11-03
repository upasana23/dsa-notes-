/*
 * Program 31: Inverted Right Triangle Pattern
 * Topic: Nested Loops
 */
#include <stdio.h>

int main(void) {
    int rows = 5;
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

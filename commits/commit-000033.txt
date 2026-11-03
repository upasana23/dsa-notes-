/*
 * Program 33: Floyd's Triangle
 * Topic: Consecutive Number Patterns
 */
#include <stdio.h>

int main(void) {
    int rows = 4, num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%2d ", num++);
        }
        printf("\n");
    }
    return 0;
}

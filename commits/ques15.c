/*
 * Program 15: Multiplication Table
 * Topic: For Loop
 */
#include <stdio.h>

int main(void) {
    int num = 7;
    printf("Multiplication Table for %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %2d = %2d\n", num, i, num * i);
    }
    return 0;
}

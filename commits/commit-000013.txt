/*
 * Program 13: Sum of First N Natural Numbers
 * Topic: Loops
 */
#include <stdio.h>

int main(void) {
    int n = 10;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    return 0;
}

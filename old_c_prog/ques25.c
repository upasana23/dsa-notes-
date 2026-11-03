/*
 * Program 25: Sum of Digits
 * Topic: While Loop & Modulo
 */
#include <stdio.h>

int main(void) {
    int n = 4567;
    int temp = n, sum = 0;

    while (temp > 0) {
        sum += (temp % 10);
        temp /= 10;
    }

    printf("Sum of digits of %d is: %d\n", n, sum);
    return 0;
}

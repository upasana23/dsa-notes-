/*
 * Program 24: Count Number of Digits
 * Topic: While Loop
 */
#include <stdio.h>

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    if (n < 0) n = -n;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main(void) {
    int n = 987654;
    printf("Number of digits in %d: %d\n", n, countDigits(n));
    return 0;
}

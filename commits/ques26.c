/*
 * Program 26: Compute x raised to power y
 * Topic: Binary Exponentiation
 */
#include <stdio.h>

long long power(long long base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

int main(void) {
    long long base = 2;
    int exp = 10;
    printf("%lld^%d = %lld\n", base, exp, power(base, exp));
    return 0;
}

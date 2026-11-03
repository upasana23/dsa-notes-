/*
 * Program 68: Recursive Power Function (Exponentiation by Squaring)
 * Topic: Divide and Conquer Recursion
 */
#include <stdio.h>

double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (exp < 0) return 1.0 / power(base, -exp);

    double half = power(base, exp / 2);
    if (exp % 2 == 0) return half * half;
    return half * half * base;
}

int main(void) {
    printf("2.0 ^ 10 = %.0f\n", power(2.0, 10));
    return 0;
}

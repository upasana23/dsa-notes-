/*
 * Program 22: Greatest Common Divisor (GCD)
 * Topic: Euclidean Algorithm
 */
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main(void) {
    int a = 56, b = 98;
    printf("GCD of %d and %d is: %d\n", a, b, gcd(a, b));
    return 0;
}

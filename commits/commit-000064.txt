/*
 * Program 64: Factorial Using Recursion
 * Topic: Recursion & Base Cases
 */
#include <stdio.h>

unsigned long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main(void) {
    int n = 7;
    printf("%d! = %llu\n", n, fact(n));
    return 0;
}

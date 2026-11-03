/*
 * Program 66: Sum of First N Numbers Using Recursion
 * Topic: Direct Recursion
 */
#include <stdio.h>

int sumRecursive(int n) {
    if (n <= 1) return n;
    return n + sumRecursive(n - 1);
}

int main(void) {
    int n = 100;
    printf("Sum 1..%d = %d\n", n, sumRecursive(n));
    return 0;
}

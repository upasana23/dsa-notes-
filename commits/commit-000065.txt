/*
 * Program 65: Nth Fibonacci Term Using Recursion
 * Topic: Tree Recursion
 */
#include <stdio.h>

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n = 8;
    printf("Fibonacci term at index %d is: %d\n", n, fib(n));
    return 0;
}

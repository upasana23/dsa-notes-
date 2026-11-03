/*
 * Program 14: Factorial (Iterative)
 * Topic: Loops & Accumulators
 */
#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(void) {
    int num = 6;
    printf("Factorial of %d = %llu\n", num, factorial(num));
    return 0;
}

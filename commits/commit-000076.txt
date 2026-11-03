/*
 * Program 76: Function Pointers as Callbacks
 * Topic: Higher-Order Functions in C
 */
#include <stdio.h>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

void compute(int a, int b, int (*operation)(int, int)) {
    printf("Result: %d\n", operation(a, b));
}

int main(void) {
    compute(5, 4, add);
    compute(5, 4, multiply);
    return 0;
}

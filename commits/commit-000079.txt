/*
 * Program 79: Add Two Complex Numbers Using Struct
 * Topic: Value Semantics with Structures
 */
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

int main(void) {
    Complex c1 = {2.5, 3.5}, c2 = {1.5, 2.5};
    Complex sum = add(c1, c2);
    printf("Sum: %.1f + %.1fi\n", sum.real, sum.imag);
    return 0;
}

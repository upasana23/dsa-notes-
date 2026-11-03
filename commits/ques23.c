/*
 * Program 23: Least Common Multiple (LCM)
 * Topic: Relation: LCM * GCD = a * b
 */
#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(void) {
    int a = 12, b = 18;
    printf("LCM of %d and %d is: %d\n", a, b, lcm(a, b));
    return 0;
}

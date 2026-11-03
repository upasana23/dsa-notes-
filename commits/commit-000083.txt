/*
 * Program 83: Check if a Number is Power of Two (Bitwise Trick)
 * Topic: Bit Manipulation: n & (n - 1)
 */
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(void) {
    int val = 64;
    printf("%d is power of two? %s\n", val, isPowerOfTwo(val) ? "Yes" : "No");
    return 0;
}

/*
 * Program 84: Count Set Bits (Brian Kernighan's Algorithm)
 * Topic: Bit Tricks
 */
#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(void) {
    int n = 29; // 11101 (4 set bits)
    printf("Set bits in %d: %d\n", n, countSetBits(n));
    return 0;
}

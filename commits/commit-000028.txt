/*
 * Program 28: Binary to Decimal Conversion
 * Topic: Radix Conversion
 */
#include <stdio.h>

int binaryToDecimal(long long binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        int last_digit = binary % 10;
        decimal += last_digit * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

int main(void) {
    long long b = 11101;
    printf("Decimal representation of %lld is: %d\n", b, binaryToDecimal(b));
    return 0;
}

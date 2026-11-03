/*
 * Program 19: Reverse an Integer
 * Topic: Modulo and Division
 */
#include <stdio.h>

int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main(void) {
    int num = 12345;
    printf("Original: %d, Reversed: %d\n", num, reverseNumber(num));
    return 0;
}

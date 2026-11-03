/*
 * Program 20: Check Palindrome Number
 * Topic: Mathematical Logic
 */
#include <stdio.h>

int main(void) {
    int num = 12321;
    int temp = num, rev = 0;

    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    if (num == rev) {
        printf("%d is a Palindrome.\n", num);
    } else {
        printf("%d is NOT a Palindrome.\n", num);
    }
    return 0;
}

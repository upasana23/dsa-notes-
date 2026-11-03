/*
 * Program 21: Check Armstrong Number
 * Topic: Digits & Powers
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int num = 153, temp = num, sum = 0, digits = 0;

    int t = num;
    while (t != 0) {
        digits++;
        t /= 10;
    }

    temp = num;
    while (temp != 0) {
        int rem = temp % 10;
        int p = 1;
        for (int i = 0; i < digits; i++) p *= rem;
        sum += p;
        temp /= 10;
    }

    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is NOT an Armstrong number.\n", num);
    }
    return 0;
}

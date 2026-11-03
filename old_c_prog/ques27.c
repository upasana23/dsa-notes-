/*
 * Program 27: Decimal to Binary Conversion
 * Topic: Radix Conversion
 */
#include <stdio.h>

void printBinary(int n) {
    int binary[32];
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main(void) {
    int num = 29;
    printf("Binary of %d is: ", num);
    printBinary(num);
    printf("\n");
    return 0;
}

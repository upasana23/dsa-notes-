/*
 * Program 34: Pascal's Triangle
 * Topic: Combinatorics & Combinations
 */
#include <stdio.h>

int main(void) {
    int rows = 5;
    for (int i = 0; i < rows; i++) {
        int val = 1;
        for (int space = 1; space <= rows - i; space++) printf(" ");
        for (int j = 0; j <= i; j++) {
            printf("%d ", val);
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}

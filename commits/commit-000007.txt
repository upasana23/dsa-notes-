/*
 * Program 07: Check Even or Odd
 * Topic: Conditional Statements
 */
#include <stdio.h>

int main(void) {
    int num = 42;
    if (num % 2 == 0) {
        printf("%d is Even.\n", num);
    } else {
        printf("%d is Odd.\n", num);
    }
    return 0;
}

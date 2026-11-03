/*
 * Program 08: Largest of Three Numbers
 * Topic: Nested Conditions
 */
#include <stdio.h>

int main(void) {
    int a = 45, b = 89, c = 23;
    int largest;

    if (a >= b && a >= c) {
        largest = a;
    } else if (b >= a && b >= c) {
        largest = b;
    } else {
        largest = c;
    }

    printf("The largest among %d, %d, and %d is: %d\n", a, b, c, largest);
    return 0;
}

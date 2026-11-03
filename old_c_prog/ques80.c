/*
 * Program 80: Memory Difference: struct vs union
 * Topic: Memory Layout & Overlapping Fields
 */
#include <stdio.h>

struct S {
    int i;
    double d;
};

union U {
    int i;
    double d;
};

int main(void) {
    printf("Size of struct: %zu bytes\n", sizeof(struct S));
    printf("Size of union:  %zu bytes\n", sizeof(union U));
    return 0;
}

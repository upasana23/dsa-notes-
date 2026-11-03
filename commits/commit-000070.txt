/*
 * Program 70: Pointer Basics: Addresses and Dereferencing
 * Topic: Memory Model in C
 */
#include <stdio.h>

int main(void) {
    int value = 42;
    int* ptr = &value;

    printf("Value: %d\n", value);
    printf("Address of value (&value): %p\n", (void*)&value);
    printf("Pointer value (ptr): %p\n", (void*)ptr);
    printf("Dereferenced value (*ptr): %d\n", *ptr);
    return 0;
}

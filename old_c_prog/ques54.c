/*
 * Program 54: Copy String Without Using strcpy()
 * Topic: Strings & Pointers
 */
#include <stdio.h>

void stringCopy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

int main(void) {
    char source[] = "Algorithms";
    char destination[50];

    stringCopy(destination, source);
    printf("Copied string: %s\n", destination);
    return 0;
}

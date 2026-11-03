/*
 * Program 53: String Length Without Using strlen()
 * Topic: Character Arrays & Null Terminators
 */
#include <stdio.h>

int stringLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    const char msg[] = "Data Structures in C";
    printf("Length of \"%s\" is: %d\n", msg, stringLength(msg));
    return 0;
}

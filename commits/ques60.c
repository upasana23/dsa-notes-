/*
 * Program 60: Convert String to Uppercase and Lowercase
 * Topic: ASCII Character Shifts
 */
#include <stdio.h>

void toUpper(char* s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

int main(void) {
    char msg[] = "pointer arithmetic";
    toUpper(msg);
    printf("Uppercase: %s\n", msg);
    return 0;
}

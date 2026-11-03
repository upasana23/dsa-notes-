/*
 * Program 55: Concatenate Two Strings Without Using strcat()
 * Topic: String Manipulation
 */
#include <stdio.h>

void stringConcat(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') i++;
    int j = 0;
    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
}

int main(void) {
    char str1[50] = "Hello ";
    char str2[] = "World!";
    stringConcat(str1, str2);
    printf("Result: %s\n", str1);
    return 0;
}

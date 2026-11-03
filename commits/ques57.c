/*
 * Program 57: Reverse a String In-Place
 * Topic: Two Pointers on Strings
 */
#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(void) {
    char str[] = "Recursion";
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

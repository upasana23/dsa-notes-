/*
 * Program 63: Remove All Whitespaces from a String
 * Topic: String In-Place Compaction
 */
#include <stdio.h>
#include <ctype.h>

void removeSpaces(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main(void) {
    char str[] = "C  Data   Structures   & Algorithms";
    removeSpaces(str);
    printf("Compacted: %s\n", str);
    return 0;
}

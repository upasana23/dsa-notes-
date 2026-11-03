/*
 * Program 61: Count Words in a Sentence
 * Topic: State Machine / Tokenization
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int countWords(const char* s) {
    int count = 0;
    bool inWord = false;

    while (*s) {
        if (isspace(*s)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
        s++;
    }
    return count;
}

int main(void) {
    const char text[] = "  Mastering   algorithms in C requires practice  ";
    printf("Word count: %d\n", countWords(text));
    return 0;
}

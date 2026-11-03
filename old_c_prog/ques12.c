/*
 * Program 12: Character Classification
 * Topic: Characters & ASCII
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch = 'A';

    if (isalpha(ch)) {
        printf("'%c' is an Alphabet.\n", ch);
    } else if (isdigit(ch)) {
        printf("'%c' is a Digit.\n", ch);
    } else {
        printf("'%c' is a Special Character.\n", ch);
    }
    return 0;
}

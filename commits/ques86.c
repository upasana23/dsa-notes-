/*
 * Program 86: Count Characters in a String Stream
 * Topic: Stream Simulation
 */
#include <stdio.h>

int main(void) {
    const char text[] = "Structured learning of C programming.\n";
    int chars = 0, lines = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        chars++;
        if (text[i] == '\n') lines++;
    }

    printf("Total Characters: %d, Total Lines: %d\n", chars, lines);
    return 0;
}

/*
 * Program 59: Count Vowels, Consonants, and Digits
 * Topic: String Parsing
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[] = "C Programming 2026!";
    int vowels = 0, consonants = 0, digits = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(c)) {
            digits++;
        }
    }

    printf("Vowels: %d, Consonants: %d, Digits: %d\n", vowels, consonants, digits);
    return 0;
}

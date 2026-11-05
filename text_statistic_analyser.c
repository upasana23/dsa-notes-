
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char text[MAX];
    int frequency[256] = {0};

    int characters = 0;
    int words = 0;
    int vowels = 0;
    int consonants = 0;
    int uppercase = 0;
    int lowercase = 0;
    int digits = 0;
    int spaces = 0;
    int special = 0;

    printf("========== TEXT STATISTICS ANALYZER ==========\n");

    printf("Enter a text:\n");
    fgets(text, MAX, stdin);

    int length = strlen(text);

    // Remove trailing newline
    if (length > 0 && text[length - 1] == '\n') {
        text[--length] = '\0';
    }

    int inWord = 0;

    for (int i = 0; text[i] != '\0'; i++) {

        unsigned char ch = (unsigned char)text[i];

        characters++;
        frequency[ch]++;

        if (isspace(ch)) {
            spaces++;
            inWord = 0;
        }
        else if (!inWord) {
            words++;
            inWord = 1;
        }

        if (isupper(ch))
            uppercase++;

        if (islower(ch))
            lowercase++;

        if (isalpha(ch)) {
            char c = tolower(ch);

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                vowels++;
            }
            else {
                consonants++;
            }
        }
        else if (isdigit(ch)) {
            digits++;
        }
        else if (!isspace(ch)) {
            special++;
        }
    }

    // Find most frequent character
    int maxFrequency = 0;
    int mostFrequent = -1;

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequent = i;
        }
    }

    printf("\n========== TEXT ANALYSIS ==========\n");

    printf("Total Characters : %d\n", characters);
    printf("Total Words      : %d\n", words);
    printf("Vowels           : %d\n", vowels);
    printf("Consonants       : %d\n", consonants);
    printf("Uppercase        : %d\n", uppercase);
    printf("Lowercase        : %d\n", lowercase);
    printf("Digits           : %d\n", digits);
    printf("Spaces           : %d\n", spaces);
    printf("Special Characters: %d\n", special);

    if (mostFrequent != -1) {
        printf("Most Frequent Character: '%c'\n",
               mostFrequent);
        printf("Frequency: %d\n", maxFrequency);
    }

    printf("\n========== CHARACTER FREQUENCY ==========\n");

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            if (i == ' ')
                printf("[SPACE] : %d\n", frequency[i]);
            else if (i >= 32 && i <= 126)
                printf("%c : %d\n", i, frequency[i]);
            else
                printf("ASCII %d : %d\n", i, frequency[i]);
        }
    }

    return 0;
}

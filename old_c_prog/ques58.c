/*
 * Program 58: Check if a String is a Palindrome
 * Topic: String Processing
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        if (str[l++] != str[r--]) return false;
    }
    return true;
}

int main(void) {
    const char* word = "radar";
    printf("'%s' is %s\n", word, isPalindrome(word) ? "a Palindrome" : "NOT a Palindrome");
    return 0;
}

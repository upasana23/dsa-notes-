/*
 * Program 62: Check if Two Strings are Anagrams
 * Topic: Frequency Map / Hashing
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool areAnagrams(const char* s1, const char* s2) {
    if (strlen(s1) != strlen(s2)) return false;
    int count[256] = {0};

    for (int i = 0; s1[i]; i++) {
        count[(unsigned char)s1[i]]++;
        count[(unsigned char)s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main(void) {
    char s1[] = "listen", s2[] = "silent";
    printf("'%s' and '%s' are anagrams? %s\n", s1, s2, areAnagrams(s1, s2) ? "Yes" : "No");
    return 0;
}

/*
 * Program 56: Compare Two Strings Without strcmp()
 * Topic: Lexicographical Comparison
 */
#include <stdio.h>

int stringCompare(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int main(void) {
    char a[] = "apple", b[] = "apply";
    int cmp = stringCompare(a, b);
    printf("Comparison result: %d\n", cmp);
    return 0;
}

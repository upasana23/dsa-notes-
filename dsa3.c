#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValid(const char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch; // Push
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(stack[top], ch)) {
                free(stack);
                return false;
            }
            top--; // Pop
        }
    }

    bool balanced = (top == -1);
    free(stack);
    return balanced;
}

int main(void) {
    const char* test1 = "{[()]}";
    const char* test2 = "{[(])}";

    printf("%s: %s\n", test1, isValid(test1) ? "Balanced" : "Not Balanced");
    printf("%s: %s\n", test2, isValid(test2) ? "Balanced" : "Not Balanced");
    return 0;
}
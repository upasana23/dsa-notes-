
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 200

char operators[MAX];
double values[MAX];
int topOp = -1, topVal = -1;

void pushOperator(char ch) {
    operators[++topOp] = ch;
}

char popOperator() {
    return operators[topOp--];
}

void pushValue(double x) {
    values[++topVal] = x;
}

double popValue() {
    return values[topVal--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '^';
}

int infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isspace((unsigned char)infix[i])) {
            i++;
        }
        else if (isdigit((unsigned char)infix[i]) ||
                 infix[i] == '.') {
            while (isdigit((unsigned char)infix[i]) ||
                   infix[i] == '.') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        }
        else if (infix[i] == '(') {
            pushOperator(infix[i++]);
        }
        else if (infix[i] == ')') {
            while (topOp != -1 && operators[topOp] != '(') {
                postfix[j++] = popOperator();
                postfix[j++] = ' ';
            }

            if (topOp == -1)
                return 0;

            popOperator();
            i++;
        }
        else if (isOperator(infix[i])) {
            char op = infix[i];

            while (topOp != -1 &&
                   operators[topOp] != '(' &&
                   (precedence(operators[topOp]) >
                    precedence(op) ||
                   (precedence(operators[topOp]) ==
                    precedence(op) && op != '^'))) {
                postfix[j++] = popOperator();
                postfix[j++] = ' ';
            }

            pushOperator(op);
            i++;
        }
        else {
            return 0;
        }
    }

    while (topOp != -1) {
        if (operators[topOp] == '(')
            return 0;

        postfix[j++] = popOperator();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
    return 1;
}

int evaluatePostfix(char postfix[], double *result) {
    int i = 0;
    topVal = -1;

    while (postfix[i] != '\0') {
        if (isspace((unsigned char)postfix[i])) {
            i++;
        }
        else if (isdigit((unsigned char)postfix[i]) ||
                 postfix[i] == '.') {
            char *end;
            double num = strtod(&postfix[i], &end);

            if (end == &postfix[i])
                return 0;

            pushValue(num);
            i = end - postfix;
        }
        else if (isOperator(postfix[i])) {
            if (topVal < 1)
                return 0;

            double b = popValue();
            double a = popValue();
            double ans;

            switch (postfix[i]) {
                case '+': ans = a + b; break;
                case '-': ans = a - b; break;
                case '*': ans = a * b; break;

                case '/':
                    if (b == 0) {
                        printf("Division by zero!\n");
                        return 0;
                    }
                    ans = a / b;
                    break;

                case '^': ans = pow(a, b); break;

                default: return 0;
            }

            pushValue(ans);
            i++;
        }
        else {
            return 0;
        }
    }

    if (topVal != 0)
        return 0;

    *result = popValue();
    return 1;
}

int main() {
    char infix[MAX], postfix[MAX * 2];
    double result;

    printf("Enter Infix Expression: ");
    fgets(infix, MAX, stdin);

    topOp = -1;

    if (!infixToPostfix(infix, postfix)) {
        printf("Invalid expression!\n");
        return 1;
    }

    printf("Postfix Expression: %s\n", postfix);

    if (evaluatePostfix(postfix, &result))
        printf("Result: %.2lf\n", result);
    else
        printf("Expression could not be evaluated!\n");

    return 0;
}

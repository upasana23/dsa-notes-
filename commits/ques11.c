/*
 * Program 11: Simple Calculator Using switch-case
 * Topic: Switch Statement
 */
#include <stdio.h>

int main(void) {
    char op = '+';
    double num1 = 12.5, num2 = 3.5;

    switch (op) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Error: Unknown operator\n");
    }
    return 0;
}

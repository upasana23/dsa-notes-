/*
 * Program 10: Simple Interest Calculator
 * Topic: Math Formula Implementation
 */
#include <stdio.h>

int main(void) {
    double principal = 10000.0;
    double rate = 5.5; // 5.5% annual
    double time = 3.0; // 3 years

    double simple_interest = (principal * rate * time) / 100.0;
    printf("Principal: $%.2f\n", principal);
    printf("Rate: %.2f%%\n", rate);
    printf("Time: %.1f years\n", time);
    printf("Simple Interest: $%.2f\n", simple_interest);
    printf("Total Amount: $%.2f\n", principal + simple_interest);
    return 0;
}

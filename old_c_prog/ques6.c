/*
 * Program 06: Temperature Conversion (Celsius to Fahrenheit)
 * Topic: Floating-point Math
 */
#include <stdio.h>

int main(void) {
    float celsius = 37.0f;
    float fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}

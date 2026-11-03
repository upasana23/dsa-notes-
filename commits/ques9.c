/*
 * Program 09: Check Leap Year
 * Topic: Logical Operators
 */
#include <stdio.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main(void) {
    int year = 2024;
    if (isLeapYear(year)) {
        printf("%d is a Leap Year.\n", year);
    } else {
        printf("%d is NOT a Leap Year.\n", year);
    }
    return 0;
}

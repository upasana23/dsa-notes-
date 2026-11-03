/*
 * Program 37: Sum and Average of Array Elements
 * Topic: Arrays & Reduction
 */
#include <stdio.h>

int main(void) {
    int arr[] = {12, 45, 67, 89, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < n; i++) sum += arr[i];
    double avg = (double)sum / n;

    printf("Sum: %d, Average: %.2f\n", sum, avg);
    return 0;
}

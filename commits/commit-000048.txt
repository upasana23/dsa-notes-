/*
 * Program 48: 2D Matrix Representation & Traversal
 * Topic: 2D Arrays
 */
#include <stdio.h>

int main(void) {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matrix (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

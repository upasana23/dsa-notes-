/*
 * Program 75: Allocate and Free a 2D Array Dynamically
 * Topic: Pointer-to-Pointer (int**)
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows = 3, cols = 4;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    return 0;
}

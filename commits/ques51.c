/*
 * Program 51: Transpose of a Matrix
 * Topic: Matrix Transformation
 */
#include <stdio.h>

int main(void) {
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int trans[3][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    printf("Transposed Matrix (3x2):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

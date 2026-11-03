/*
 * Program 52: Sum of Diagonals of a Square Matrix
 * Topic: Matrix Traversal
 */
#include <stdio.h>

int main(void) {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int mainDiag = 0, antiDiag = 0;

    for (int i = 0; i < 3; i++) {
        mainDiag += mat[i][i];
        antiDiag += mat[i][3 - 1 - i];
    }

    printf("Main Diagonal Sum: %d, Anti-Diagonal Sum: %d\n", mainDiag, antiDiag);
    return 0;
}

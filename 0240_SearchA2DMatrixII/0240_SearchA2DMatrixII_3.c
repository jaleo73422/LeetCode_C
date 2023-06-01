#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = matrixSize - 1, col = 0;

    while(row >= 0 && col < *matrixColSize) {
        if(target == matrix[row][col])  return 1;
        else if(target < matrix[row][col])  row--;
        else  col++;
    }

    return 0;
}

void main() {
    // example 1
    // output = 1
    // int matrix[][5] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    // int target = 5;
    // int m = 5;
    // int a = 5;
    // int* n = &a;

    // example 2
    // output = 0
    // int matrix[][4] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    // int target = 20;
    // int m = 5;
    // int a = 5;
    // int* n = &a;

    // printf("%d ", searchMatrix(matrix, m, n, target));
}
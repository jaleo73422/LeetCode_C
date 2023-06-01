#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int l = 0, r = matrixSize * *matrixColSize - 1;

    while(l <= r) {
        int m = l + (r - l) / 2;
        int row = m / *matrixColSize;
        int col = m % *matrixColSize;

        if(matrix[row][col] == target)  return 1;
        else if(matrix[row][col] > target)
            r = m - 1;
        else
            l = m + 1;
    }

    return 0;
}

void main() {
    // example 1
    // output = 1
    // int matrix[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // int target = 3;
    // int m = 3;
    // int a = 4;
    // int* n = &a;

    // example 2
    // output = 0
    // int matrix[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // int target = 13;
    // int m = 3;
    // int a = 4;
    // int* n = &a;

//     printf("%d ", searchMatrix(matrix, m, n, target));
}
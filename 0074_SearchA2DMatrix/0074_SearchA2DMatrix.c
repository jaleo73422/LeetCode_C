#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = -1;
   
    for(int i = 0; i < matrixSize; i++) {
        if(matrix[i][*matrixColSize - 1] > target && matrix[i][0] < target) {
            row = i;
            break;
        } else if(matrix[i][*matrixColSize - 1] == target || matrix[i][0] == target)
            return 1;
    }
   
    if(row == -1)  return 0;


    for(int i = 1; i < *matrixColSize - 1; i++) {
        if(matrix[row][i] == target)
            return 1;
        if(matrix[row][i] > target)
            return 0;
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
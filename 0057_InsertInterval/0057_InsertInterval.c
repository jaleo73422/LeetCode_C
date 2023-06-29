#include <stdio.h>
#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;
    int i = 0;

    // before overlap
    while(i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[*returnSize] = malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[(*returnSize)++] = 2;
        i++;
    }

    // overlap
    while(i < intervalsSize && !(intervals[i][0] > newInterval[1])) {
        newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
        newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
        i++;
    }

    result[*returnSize] = malloc(sizeof(int) * 2);
    result[*returnSize][0] = newInterval[0];
    result[*returnSize][1] = newInterval[1];
    (*returnColumnSizes)[(*returnSize)++] = 2;

    // after overlap
    while(i < intervalsSize) {
        result[*returnSize] = malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[(*returnSize)++] = 2;
        i++;
    }

    return result;
}

void main() {
}
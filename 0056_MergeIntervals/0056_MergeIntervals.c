#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return **(int**)a - **(int**)b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int** result = malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int* pre = intervals[0];

    for(int i = 1; i < intervalsSize; i++) {
        if(intervals[i][0] <= pre[1]) {
            pre[1] = intervals[i][1] > pre[1] ? intervals[i][1] : pre[1];
        } else {
            result[*returnSize] = malloc(sizeof(int) * 2);
            result[*returnSize][0] = pre[0];
            result[*returnSize][1] = pre[1];
            (*returnColumnSizes)[(*returnSize)++] = 2;
            pre = intervals[i];
        }
    }

    result[*returnSize] = malloc(sizeof(int) * 2);
    result[*returnSize][0] = pre[0];
    result[*returnSize][1] = pre[1];
    (*returnColumnSizes)[(*returnSize)++] = 2;
            
    return result;
}


int main() {
   return 0;
}
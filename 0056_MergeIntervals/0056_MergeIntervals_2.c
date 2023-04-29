#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    if(**(int**)a != **(int**)b)  return **(int**)a - **(int**)b;
    else  return (*(int**)b)[1] - (*(int**)a)[1];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    int** new_array = malloc(sizeof(int*) * intervalsSize * 2);
    int new_i = 0;

    for(int i = 0; i < intervalsSize; i++) {
        new_array[new_i] = malloc(sizeof(int) * 2);
        new_array[new_i][0] = intervals[i][0];
        new_array[new_i++][1] = 1;
        new_array[new_i] = malloc(sizeof(int) * 2);
        new_array[new_i][0] = intervals[i][1];
        new_array[new_i++][1] = -1;
    }

    qsort(new_array, intervalsSize * 2, sizeof(int*), cmp);

    int sum = 0;
    int** result = malloc(sizeof(int*) * intervalsSize);

    for(int i = 0; i < intervalsSize * 2; i++) {
        if(sum == 0 && new_array[i][1] > 0) {
            result[*returnSize] = malloc(sizeof(int) * 2);
            result[*returnSize][0] = new_array[i][0];
            result[*returnSize][1] = 0;
        } else if(sum > 0 && sum + new_array[i][1] == 0) {
            result[*returnSize][1] = new_array[i][0]; 
            (*returnColumnSizes)[(*returnSize)++] = 2;
        }
        sum += new_array[i][1];
    }

    return result;
}

int main() {
   return 0;
}
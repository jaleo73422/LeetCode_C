#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int* result = (int*) malloc((n + 1) * sizeof(int));
    // *returnSize = n + 1;
    result[0] = 0;

    for(int i = 1; i <= n; i++)
        result[i] = result[i >> 1] + (i & 1);

    return result;
}


void main() {
    // example 1
    // output = {0, 1, 1}
    // int n = 2;

    // example 2
    // output = {0, 1, 1, 2, 1, 2}
    int n = 5;

    int* returnSize = 0;
    int* result = countBits(n, returnSize);

    for(int i = 0; i <= n; i++)
        printf("%d ", result[i]);
}
#include <stdio.h>
#include <stdlib.h>

int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int M = 1000000007;

    *queriesColSize = 2;
    *returnSize = queriesSize;

    int power[30] = {0};
    int powerSize = 0;
    int* res = calloc(queriesSize, sizeof(int));

    for(int i = 0; i < 30; i++) {
        if(n & 1 == 1)
            power[powerSize++] = i;
        
        n >>= 1;
        if(n == 0)  break;
    }

    int prefix_pow[powerSize];
    for(int i = 0; i < powerSize; i++)
        if(i == 0)  prefix_pow[i] = power[i];
        else  prefix_pow[i] = prefix_pow[i - 1] + power[i];

    int pow2[30 * 30] = {1};
    for(int i = 1; i < 30 * 30; i++)
        pow2[i] = pow2[i - 1] * 2 % M;

    for(int i = 0; i < queriesSize; i++) {
        int tem = queries[i][0] == 0 ? 0 : prefix_pow[queries[i][0] - 1];
        int diff = prefix_pow[queries[i][1]] - tem;
        res[i] = pow2[diff];
    }
    
    return res;
}

void main() {
}
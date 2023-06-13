#include <stdio.h>
#include <stdlib.h>

int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int M = 1000000007;

    *queriesColSize = 2;
    *returnSize = queriesSize;

    int power[30] = {0};
    int powerSize = 0;
    int powerVal = 1;
    int tem = n;
    int* res = calloc(queriesSize, sizeof(int));

    if(tem & 1 == 1)
        power[powerSize++] = 1;
    tem >>= 1;

    while(tem != 0) {
        powerVal <<= 1;
        if(tem & 1 == 1)
            power[powerSize++] = powerVal;
        tem >>= 1;
    }

    for(int i = 0; i < queriesSize; i++) {
        long long prod = 1;
        for(int j = queries[i][0]; j <= queries[i][1]; j++)
            prod = prod * power[j] % M;
        res[i] = prod;
    }
    
    return res;
}

void main() {
}
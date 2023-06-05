#include <stdio.h>

long long maximumOr(int* nums, int numsSize, int k) {
    int* prefix = calloc(numsSize, sizeof(int));
    int* suffix = calloc(numsSize, sizeof(int));

    for(int i = 1; i < numsSize; i++)
        prefix[i] = prefix[i - 1] | nums[i - 1];
    
    for(int i = numsSize - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] | nums[i + 1];

    long long res = 0;

    for(int i = 0; i < numsSize; i++) {
        long long tem = prefix[i] | ((long long) nums[i] << k) | suffix[i];
        res = tem > res ? tem : res;
    }

    return res;
}

void main() {
    // example 1
    // output = 30
    // int nums[] = {12, 9};
    // int k = 1;

    // example 2
    // output = 35
    int nums[] = {8, 1, 2};
    int k = 2;

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%ld ", maximumOr(nums, n, k));
}
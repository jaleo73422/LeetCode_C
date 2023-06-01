#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {    
    int32_t lowestBit1 = 1;
    int allXOr = 0;
    int* res = calloc(2, sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++)
        allXOr ^= nums[i];

    lowestBit1 = allXOr & (-(unsigned)allXOr);

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] & lowestBit1)
            res[1] ^= nums[i];
        else
            res[0] ^= nums[i];
    }

    return res;
}

void main() {
    // example 1
    // output = {3, 5}
    int nums[] = {1, 2, 1, 3, 2, 5};

    // example 2
    // // output = {-1, 0}
    // int nums[] = {-1, 0};

    // example 3
    // output = {1, 0}
    // int nums[] = {0, 1};

    int n = sizeof(nums) / sizeof(nums[0]);
    int* returnSize;

    int* ans = singleNumber(nums, n, returnSize);

    printf("%d %d \n", ans[0], ans[1]);
}
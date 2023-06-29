#include <stdio.h>

int singleNumber(int* nums, int numsSize){    
    int res = nums[0];

    for(int i = 1; i < numsSize; i++)
        res ^= nums[i];

    return res;
}

void main() {
    // example 1
    // output = 1
    // int nums[] = {2, 2, 1};

    // example 2
    // output = 5
    // int nums[] = {4, 1, 2, 1, 2};

    // example 3
    // output = 1
    int nums[] = {1};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", singleNumber(nums, n));
}
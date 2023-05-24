#include <stdio.h>
#include <stdint.h>

int missingNumber(int* nums, int numsSize){
    int res = numsSize;

    for(int i = 0; i < numsSize; i++)
        res += (i - nums[i]);
    
    return res;
}

int main() {
    // example 1
    // output = 2
    // int nums[] = {3, 0, 1};

    // example 2
    // output = 2
    // int nums[] = {0, 1};

    // example 3
    // output = 8
    int nums[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", missingNumber(nums, n));

    return 0;
}
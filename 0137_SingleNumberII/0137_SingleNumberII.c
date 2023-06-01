#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    
    for(int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    
    return ones;
}


void main() {
    // example 1
    // output = 3
    // int nums[] = {2, 2, 3, 2};

    // example 2
    // output = 99
    int nums[] = {0, 1, 0, 1, 0, 1, 99};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", singleNumber(nums, n));
}
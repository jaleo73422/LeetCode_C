#include <stdio.h>
#include <stdint.h>

int singleNumber(int* nums, int numsSize){
    int res = 0;
    
    for(int i = 0; i < 32; i++) {
        int digitSum = 0;

        for(int j = 0; j < numsSize; j++)
            digitSum += (nums[j] >> 31 - i) & 1;

        if(digitSum % 3)
            res += (uint32_t) 1 << (31 - i);
    }

    return res;
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
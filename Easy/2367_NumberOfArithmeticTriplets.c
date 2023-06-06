#include <stdio.h>

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int res = 0;
    int hash[201];
    
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] >= 2 * diff && hash[nums[i] - diff] && hash[nums[i] - 2 * diff])
            res++;
            
      hash[nums[i]] = 1;
    }
    
    return res;
}


void main() {
}
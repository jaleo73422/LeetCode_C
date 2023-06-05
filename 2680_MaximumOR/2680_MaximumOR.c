#include <stdio.h>

long long maximumOr(int* nums, int numsSize, int k) {
    int count[30] = {0};
    long long res = 0;

    for(int i = 0; i < numsSize; i++)
        for(int j = 0; j < 30; j++)
            if((nums[i] >> j) & 1)
                count[j]++;
    
    for(int i = 0; i < numsSize; i++) {
        int tem_count[30];

        // remove nums[i]
        for(int j = 0; j < 30; j++)
            if((nums[i] >> j) & 1)
                tem_count[j] = count[j] - 1;
            else
                tem_count[j] = count[j];
        
        long long tem = 0;  // all or without nums[i]

        for(int j = 0; j < 30; j++)
            if(tem_count[j] > 0)
                tem += (1 << j);
        
        tem |= (long long) nums[i] << k;
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
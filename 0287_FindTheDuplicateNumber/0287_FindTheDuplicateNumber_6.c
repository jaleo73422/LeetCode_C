#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int res = 0;
    int bit1_nums, bit1_n;
    int shift = 0, n = numsSize - 1;

    while(n != 0) {
        bit1_nums = 0;
        bit1_n = 0;

        for(int i = 0; i < numsSize; i++) {
            if((nums[i] >> shift) & 1)
                bit1_nums++;
            
            if((i >> shift) & 1)
                bit1_n++;
        }

        if(bit1_nums > bit1_n)
            res += (1 << shift);

        shift++;
        n >>= 1;
    }

    return res;
}

int main() {
    // example 1
    // output = 2
    // int nums[] = {1, 3, 4, 2, 2};

    // example 2
    // output = 3
    int nums[] = {3, 1, 3, 4, 2};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", findDuplicate(nums, n));

    return 0;
}
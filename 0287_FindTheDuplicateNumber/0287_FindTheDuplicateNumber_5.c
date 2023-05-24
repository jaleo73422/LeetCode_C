#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int l = 1, r = numsSize - 1;
    int m;
    
    while(l < r) {
        m = l + (r - l) / 2;
        int count = 0;

        for(int i = 0; i < numsSize; i++)
            if(nums[i] <= m)  count++;
        
        if(count > m)  r = m;
        else  l = m + 1;
    }

    return l;
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
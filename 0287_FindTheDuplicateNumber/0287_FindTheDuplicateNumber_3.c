#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int* nums, int numsSize) {
    int* sort_arr = (int*) calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        sort_arr[nums[i]]++;

        if(sort_arr[nums[i]] > 1)
            return nums[i];
    }

    return -1;
}

void main() {
    // example 1
    // output = 2
    // int nums[] = {1, 3, 4, 2, 2};

    // example 2
    // output = 3
    int nums[] = {3, 1, 3, 4, 2};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", findDuplicate(nums, n));
}
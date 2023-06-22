#include <stdio.h>

void swap(int* a, int* b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}

int findDuplicate(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++)
        while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
            swap(&nums[i], &nums[nums[i] - 1]);

    for(int i = 0; i < numsSize; i++)
        if(nums[i] != i + 1)
            return nums[i];

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
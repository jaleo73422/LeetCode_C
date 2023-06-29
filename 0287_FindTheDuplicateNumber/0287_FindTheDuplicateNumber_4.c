#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int findDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 1; i < numsSize; i++)
        if (nums[i] == nums[i - 1])
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
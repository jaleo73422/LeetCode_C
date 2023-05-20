#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int copy[numsSize];
    int copy_idx = 0;
    int times = k % numsSize;

    for(int i = numsSize - times; i < numsSize; i++)
        copy[copy_idx++] = nums[i];

    for(int i = 0; i < numsSize - times; i++)
        copy[copy_idx++] = nums[i];

    for(int i = 0; i < numsSize; i++)
        nums[i] = copy[i];
}

int main() {
    // example 1
    // output = {5, 6, 7, 1, 2, 3, 4}
    // int nums[] = {1, 2, 3, 4, 5, 6, 7};
    // int k = 3;

    // example 2
    // output = {3, 99, -1, -100}
    // int nums[] = {-1, -100, 3, 99};
    // int k = 2;

    // example 3
    // output = {-1}
    int nums[] = {-1};
    int k = 2;

    int n = sizeof(nums) / sizeof(nums[0]);
    rotate(nums, n, k);

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
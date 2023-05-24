#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    fast = nums[0];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
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
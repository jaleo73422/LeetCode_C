#include <stdio.h>
#include <stdlib.h>

struct set {
    int value;
    int index;
};

int cmp(const void* a, const void* b) {
    return (*(struct set*) a).value - (*(struct set*) b).value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct set* sorted_nums = (struct set*) malloc(numsSize * sizeof(struct set));
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++) {
        sorted_nums[i].value = nums[i];
        sorted_nums[i].index = i;
    }

    qsort(sorted_nums, numsSize, sizeof(struct set*), cmp);

    int* res = calloc(2, sizeof(int));
    int left = 0, right = numsSize - 1;

    while(left < right) {
        if(sorted_nums[left].value + sorted_nums[right].value > target) {
            right--;
        } else if(sorted_nums[left].value + sorted_nums[right].value < target) {
            left++;
        } else {
            res[0] = sorted_nums[left].index;
            res[1] = sorted_nums[right].index;
            break;
        }
    }

    return res;
}

void main() {
}
#include <stdio.h>
#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize) {
    int* res = malloc(2 * sizeof(int));
    int xOr = 0, n1 = 0, n2 = 0;

    for(int i = 0; i < numsSize; i++)
        xOr ^= (i + 1) ^ nums[i];

    int lastBit1 = xOr & -xOr;

    for(int i = 0; i < numsSize; i++) {
        if((nums[i] & lastBit1) != 0)
            n1 ^= nums[i];
        else
            n2 ^= nums[i];

        if(((i + 1) & lastBit1) != 0)
            n1 ^= (i + 1);
        else
            n2 ^= (i + 1);
    }

    for (int i = 0; i < numsSize; i++) {
        if(nums[i] == n1) {
            res[0] = n1;
            res[1] = n2;
        } else {
            res[0] = n2;
            res[1] = n1;
        }
    }
    
    return res;
}

void main() {
}
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tem;
    
    tem  = b[1];
    b[1] = a[1];
    a[1] = tem;
    
    tem = b[0];
    b[0] = a[0];
    a[0] = tem;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int copy[numsSize][2], hash[numsSize][2];
    int hash_idx = 0;
    int* res = (int*) malloc(numsSize * sizeof(int));
    int res_idx = 0;

    for(int i = 0; i < numsSize; i++) {
        copy[i][0] = nums[i];
        copy[i][1] = 0;
    }

    for(int i = 0; i < numsSize; i++) {
        if(copy[i][1])  continue;
        
        int count = 1;
        
        for(int j = i + 1; j < numsSize; j++)
            if(copy[i][0] == copy[j][0]) {
                copy[j][1] = 1;
                count++;
            }
        
        hash[hash_idx][0] = copy[i][0];
        hash[hash_idx][1] = count;
        hash_idx++;
    }

    for(int i = 0; i < hash_idx - 1; i++)
        for (int j = i + 1; j < hash_idx; j++) {
            int tem = hash[i][1];

            if(tem > hash[j][1])
                swap(hash[i], hash[j]);
            else if(tem == hash[j][1])
                if(hash[j][0] > hash[i][0])
                    swap(hash[i], hash[j]);
        }

    for(int i = 0; i < hash_idx; i++)
        while(hash[i][1] != 0) {
            res[res_idx] = hash[i][0];
            res_idx++;
            hash[i][1]--;
        }

    // *returnSize = numsSize;

    return res;
}

void main() {
    int* returnSize;
    int* output;

    // example 1
    // output = {3, 1, 1, 2, 2, 2}
    // int nums[] = {1, 1, 2, 2, 2, 3};

    // example 2
    // output = {1, 3, 3, 2, 2}
    // int nums[] = {2, 3, 1, 3, 2};

    // example 3
    // output = {5, -1, 4, 4, -6, -6, 1, 1, 1}
    int nums[] = {-1, 1, -6, 4, 5, -6, 1, 4, 1};

    int nSize = sizeof(nums) / sizeof(nums[0]);
    output = frequencySort(nums, nSize, returnSize);

    for(int i = 0; i < nSize; i++)
        printf("%d ", output[i]);
}
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
    int copy[numsSize][2], table[numsSize][2];
    int tab_idx = 0, tem, count;
    int* res = (int*) malloc(numsSize * sizeof(int));
    int res_idx = 0;

    for(int i = 0; i < numsSize; i++) {
        copy[i][0] = nums[i];
        copy[i][1] = 0;
    }

    for(int i = 0; i < numsSize; i++) {
        if(copy[i][1])  continue;
        
        count = 1;
        
        for(int j = i + 1; j < numsSize; j++) {
            if(copy[i][0] == copy[j][0]) {
                copy[j][1] = 1;
                count++;
            }
        }
        
        table[tab_idx][0] = copy[i][0];
        table[tab_idx][1] = count;
        tab_idx++;
    }

    for(int i = 0; i < tab_idx - 1; i++) {        
        for (int j = i + 1; j < tab_idx; j++) {
            tem = table[i][1];

            if (tem > table[j][1])
                swap(table[i], table[j]);
            else if(tem == table[j][1])
                if(table[j][0] > table[i][0])
                    swap(table[i], table[j]);
        }
    }

    for(int i = 0; i < tab_idx; i++) {
        while (table[i][1] != 0) {
            res[res_idx] = table[i][0];
            res_idx++;
            table[i][1]--;
        }
    }

    // *returnSize = numsSize;

    return res;
}

int main() {
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

    return 0;
}
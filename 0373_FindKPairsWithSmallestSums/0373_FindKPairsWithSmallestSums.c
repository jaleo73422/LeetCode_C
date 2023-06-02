#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] + (*(int**)a)[1] - (*(int**)b)[0] - (*(int**)b)[1];
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int** res;
    int res_idx = 0;

    *returnColumnSizes = (int*) malloc(nums1Size * nums2Size * sizeof(int));
    res = (int**) malloc(nums1Size * nums2Size * sizeof(int*));

    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size; j++) {
            res[res_idx] = (int*) malloc(2 * sizeof(int));
            res[res_idx][0] = nums1[i];
            res[res_idx][1] = nums2[j];

            (*returnColumnSizes)[res_idx] = 2;
            res_idx++;
        }
    }

    qsort(res, nums1Size * nums2Size, sizeof(int*), cmp);

    if(res_idx < k)  *returnSize = res_idx;
    else  *returnSize = k;
    
    return res;
}

void main() {
}
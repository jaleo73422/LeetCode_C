#include <stdio.h>
#include <stdlib.h>

int countSmallerOrEqual(int* nums1, int nums1Size, int* nums2, int nums2Size, int val) {
    long count = 0;
    int j = nums2Size - 1;

    for(int i = 0; i < nums1Size; i++) {
        while(j >= 0 && nums1[i] + nums2[j] > val)
            j--;
        
        count += j + 1;
    }

    return count;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int left = nums1[0] + nums2[0];
    int right = nums1[nums1Size - 1] + nums2[nums2Size - 1];

    while(left < right) {
        int mid = left + (right - left) / 2;
        int count = countSmallerOrEqual(nums1, nums1Size, nums2, nums2Size, mid);

        if(count < k)  left = mid + 1;
        else  right = mid;
    }

    int target = left;
    int** res;
    int res_idx = 0;
    *returnColumnSizes = (int*) malloc(nums1Size * nums2Size * sizeof(int));
    res = (int**) malloc(k * sizeof(int*));

    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size && nums1[i] + nums2[j] < target; j++) {
            res[res_idx] = (int*) malloc(2 * sizeof(int));
            res[res_idx][0] = nums1[i];
            res[res_idx][1] = nums2[j];

            (*returnColumnSizes)[res_idx] = 2;
            res_idx++;
        }                
    }

    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size && nums1[i] + nums2[j] <= target && res_idx < k; j++) {
            if(nums1[i] + nums2[j] == target) {
                res[res_idx] = (int*) malloc(2 * sizeof(int));
                res[res_idx][0] = nums1[i];
                res[res_idx][1] = nums2[j];

                (*returnColumnSizes)[res_idx] = 2;
                res_idx++;
            }
        }                
    }

    if(res_idx < k)  *returnSize = res_idx;
    else  *returnSize = k;

    return res;
}

void main() {
}
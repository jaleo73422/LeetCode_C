#include <stdio.h>

void swap(int* arr, int fi, int si, int times) {	
	for(int i = 0; i < times; i++) {
		int tem = arr[fi + i];
		arr[fi + i] = arr[si + i];
		arr[si + i] = tem;
	}
}

void rotate(int* nums, int numsSize, int k) {	
	k %= numsSize;
    if(k == 0 || k == numsSize)  return ;
    
	int first_n = numsSize - k;
	int second_n = k;
	
	while(first_n != second_n) {
		if(first_n < second_n) {
			swap(nums, numsSize - k - first_n, numsSize - k - first_n + second_n, first_n);
			second_n -= first_n;
		}else {
			swap(nums, numsSize - k - first_n, numsSize - k, second_n);
			first_n -= second_n;
		}
	}

	swap(nums, numsSize - k - first_n, numsSize - k, first_n);
}

void main() {
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
}
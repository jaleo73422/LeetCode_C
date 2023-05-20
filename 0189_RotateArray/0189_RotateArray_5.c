#include <stdio.h>

void reverseArray(int* arr, int start, int end) {
	int tem;
	
	while(start < end) {
		tem = arr[start];
		arr[start] = arr[end];
		arr[end] = tem;
		start++;
		end--;
	}
}


void rotate(int* nums, int numsSize, int k) {
	if (k == 0)  return;
	
	k = k % numsSize;

	reverseArray(nums, 0, numsSize - k - 1);
	reverseArray(nums, numsSize - k, numsSize - 1);
	reverseArray(nums, 0, numsSize - 1);
}

int main() {
    // example 1
    // output = {5, 6, 7, 1, 2, 3, 4}
    // int nums[] = {1, 2, 3, 4, 5, 6, 7};
    // int k = 3;

    // example 2
    // output = {3, 99, -1, -100}
    int nums[] = {-1, -100, 3, 99};
    int k = 2;

    int n = sizeof(nums) / sizeof(nums[0]);
    rotate(nums, n, k);

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
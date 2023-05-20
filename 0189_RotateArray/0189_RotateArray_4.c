#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)  return a;
    else  return gcd(b, a % b);
}

void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	k = numsSize - k;
	int gcd_val = gcd(k, numsSize);
	
	for(int i = 0; i < gcd_val; i++) {
		int tem = nums[i];
		int second = i;
		int first = -1;

		while(1) {
			first = (second + k) % numsSize;

			if(first == i)  break;

			nums[second] = nums[first];
			second = first;
		}

		nums[second] = tem;
	}
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
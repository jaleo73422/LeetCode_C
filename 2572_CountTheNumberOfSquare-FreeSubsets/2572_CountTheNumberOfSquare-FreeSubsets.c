#include <stdio.h>

int helper(int x) {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int s = 0;

    for(int i = 0; i < 10; i++) {
        int count = 0;

        while(x % primes[i] == 0) {
            count++;
            x /= primes[i];
        }

        if(count > 1)  return -1;          
        else if(count == 1)
            s += (1 << i);                    
    }

    return s;
}

int squareFreeSubsets(int* nums, int numsSize) {
    int dp[numsSize + 1][1024];
    long long M = 1000000007;
    int res = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i = 1; i <= numsSize; i++)
        for(int state = 0; state < (1 << 10); state++) {
            if(nums[i - 1] == 1)
                dp[i][state] = dp[i - 1][state] * 2 % M;
            else {
                dp[i][state] = dp[i - 1][state];
                int s = helper(nums[i - 1]);

                if(s != -1 && (state & s) == s)
                    dp[i][state] = (dp[i][state] + dp[i - 1][state - s]) % M;
            }

            if(i == numsSize)
                res = (res + dp[i][state]) % M;
        }

    return (res + M - 1) % M;
}

void main() {
    // example 1
    // output = 3
    int nums[] = {3, 4, 4, 5};

    // example 2
    // output = 1
    // int nums[] = {1};

    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d ", squareFreeSubsets(nums, n));
}
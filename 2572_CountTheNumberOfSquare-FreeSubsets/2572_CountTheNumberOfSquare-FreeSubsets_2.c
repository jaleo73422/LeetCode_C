#include <stdio.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int checkOut(int x) {
    for(int i = 0; i < 10; i++)
        if(x % primes[i] == 0)
            if(x / primes[i] % primes[i] == 0)
                return 1;

    return 0;
}

int squareFreeSubsets(int* nums, int numsSize) {
    int dp[numsSize + 1][1 << 10];
    long long M = 1000000007;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i = 1; i <= numsSize; i++) {
        for(int j = 0; j < (1 << 10); j++)
            dp[i][j] = dp[i - 1][j];

        if(checkOut(nums[i - 1]))  continue;

        int state = 0;
       
        for(int j = 0; j < 10; j++)
            if(nums[i - 1] % primes[j] == 0)
                state |= (1 << j);

        for(int j = 0; j < (1 << 10); j++)
            if((j & state) == 0)
                dp[i][j | state] = (dp[i][j | state] + dp[i - 1][j]) % M;
    }

    int res = 0;

    for(int i = 0; i < (1 << 10); i++)
        res = (res + dp[numsSize][i]) % M;

    return ((res - 1) % M + M) % M;
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
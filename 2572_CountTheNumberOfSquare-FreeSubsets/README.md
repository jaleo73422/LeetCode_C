# 2572. Count the Number of Square-Free Subsets

all primes appear at most 1 time <br/>

## C_1 Bitwise
```
express pormes state with binary
ex.
primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
s = 1000010011 => 2 13 23 29

dp[i][state] = subset nmbers of nums[i - 1] in state
dp[0][0] = 1
=> the answer is sum of nums[i == numsSize - 1]'s all state
if(i == numsSize)
    res = (res + dp[i][state]) % M;

if(nums[i - 1] == 1)  // nums[i] can be choosen or not
    dp[i][state] = dp[i - 1][state] * 2 % M;
else {
    dp[i][state] = dp[i - 1][state];
    int s = helper(nums[i - 1]);  // get nums[i - 1]'s state

    // s != -1 => prime numbers > 1 => don't choose
    // (state & s) == s => each prime only appear 1 time
    if(s != -1 && (state & s) == s)
        // choose nums[i - 1] + don't choose nums[i - 1]
        dp[i][state] = (dp[i][state] + dp[i - 1][state - s]) % M;
}

(state & s) == s
    s = 1 [00] 0 [0]1 00  11 => 2 13 23 29
state = 1  00 (1) 0 1(11) 11
(s, state, &) = (1, 0, 0) => don't choose
(s, state, &) = (0, 1, 0) => choose
(s, state, &) = (0, 0, 0) => don't choose
(s, state, &) = (1, 1, 1) => don't choose

return (res + M - 1) % M
delete empty set
if res = 1000000007
res = (res + dp[i][state]) % M = 0
=> return (res + M - 1) % M
```

## C_2 Bitwise
```
same as C_1

return ((res - 1) % M + M) % M;
and
return (res + M - 1) % M;
are the same
```

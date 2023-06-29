# 560. Subarray Sum Equals K

## CPP_1 Prefix Sum + Hash table
```
hash table of prefix sum
{0: 1}

key = sum - k
nums = [... X X i] X X ...
sum = [... X X i]
[X X i] => total = X + X + i = K
key = sum - k = [...] = prefix[sum - k]

nums = {1, 2, 3};
int k = 3;

      i =  -1  0 1 2
nums[i] =      1 2 3
sum     =   0  1 3 6
key     =   0 -2 0 3
value   =   1  1 2 1
```


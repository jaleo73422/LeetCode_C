# 2680. Maximum OR

## C_1 Bitwise

## C_2 Prefix sum
```
prefix = {0, 8, (8 | 1)}
  nums =    {8, 1,       2}
suffix = {      (1 | 2), 2, 0}

X X X ... nums[i] ... X X X
prefix[i] = X | X | ... = prefix[i - 1] | nums[i - 1]
suffix[i] = ... | X | X = suffix[i + 1] | nums[i + 1]
```
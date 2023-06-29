# 268. Missing Number

## C_1 Bitwise
```
                i: 0 1 2 3(numsSize)
             nums: 3 0 1
res = i ^ nums[i]: 3 ^ (0 ^ 3) ^ (1 ^ 0) ^ (2 ^ 1)

1) n ^ n = 0
2) n ^ 0 = n
3) n ^ m = m ^ n
```

## C_2
```
          i: 0 1 2 3(numsSize)
       nums: 3 0 1
res = 3        + (0 + 1 + 2) - (3 + 0 + 1)
    = numsSize + sum(i)      - sum(nums)
```
# 260. Single Number III

## _1 _2 Bitwise
```
nums = {1, 1, 3, 5}
a = 1 ^ 1 ^ 3 ^ 5 = 3 ^ 5
nums[0] = 1 = 001
nums[1] = 1 = 001
nums[2] = 3 = 011
nums[3] = 5 = 101
      a = 6 = 110 => different bit between 3 and 5

randomly select one of many bits of a 
d(bit3) = 100

bit3 is 0 b = 1 1 3 => 1 ^ 1 ^ 3 = 3
bit3 is 1 c = 5
```
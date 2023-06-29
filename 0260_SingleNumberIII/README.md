# 260. Single Number III

## C_1 C_2 Bitwise
n's lowest bit1  = n & (-n) <br/>

```
nums = {1, 1, 3, 5}
a = 1 ^ 1 ^ 3 ^ 5 = 3 ^ 5
nums[0] = 1 = 001
nums[1] = 1 = 001
nums[2] = 3 = 011
nums[3] = 5 = 101
      a = 6 = 110 => different bit between two not duplicated numbers (3 and 5)

randomly select one of all bits 1 of a
d(bit3) = 100 (choose lowest bit 1 in this problem)

nums[i] & bit3 = [1 1 3] => 1 ^ 1 ^ 3 = 3
nums[i] & bit3 = [5] => 5
```
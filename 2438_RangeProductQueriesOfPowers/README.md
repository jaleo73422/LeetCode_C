# 2438. Range Product Queries of Powers

## C_1 Bitwise

## C_2 Bitwise + Prefix sum
```
to avoid (2 ^ n) is too large
only put power of 2 in power[i]
ex. power = [1, 4, 5] => powers[i] = [2, 16, 32]

Input: n = 15, queries = [[0,1],[2,2],[0,3]]
       power = [0, 1, 2, 3] => powers = [1, 2, 4, 8]
prefix_power = [0, 1, 3, 6] 
             = [[0], [0] * [1], [0] * ... * [2], [0] * ... * [3]]
pow2 = [1, 2, 4, 8, 16, 32, ...]
```
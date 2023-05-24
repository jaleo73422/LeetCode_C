# 338. Counting Bits

```
*returnSize = n + 1;
execute in LeetCode
```

## _1 Dynamic Programmin, Bitwise
```
result[i] = result[i >> 1] + (i & 1);
          = bit 1 ~ heightest bit + bit 0

X X ... X X X X
result[i >> 1] => X X ... X X X (X)
(i & 1) => (X)
```

## _2 Dynamic Programmin
```
0 = 00[00] => 0
1 = 00[01] => 1
2 = 00[10] => 1
3 = 00[11] => 2

4 = 0(1)[00] => 1 = (1) + dp[0]
5 = 0(1)[01] => 2 = (1) + dp[1]
6 = 0(1)[10] => 2 = (1) + dp[2]
7 = 0(1)[11] => 3 = (1) + dp[3]

8 = (1)000   => 1 = (1) + dp[0]
```

## _3 _4 Dynamic Programmin, Bitwise
```
1 + result[i - (i & -i)]
i - (i & -i) => delete last bits 1

result[i] = 1 + result[i & (i - 1)]
i & (i - 1) => delete last bits 1
```
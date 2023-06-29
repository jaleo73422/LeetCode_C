# 338. Counting Bits

```
*returnSize = n + 1;
execute in LeetCode
```

## C_2 Dynamic Programmin
```c
result[0] = 0;

for(int i = 1; i <= n; i++) {
    if(offset * 2 == i)
        offset = i;

    result[i] = 1 + result[i - offset];
}
```

```
i = 0 => 000[0] => res[0] = 0

offset = 1
i = 1 => 000[1] => res[1] = 1

offset = 2
i = 2 => 00(1)[0] => res[2] = 1 = (1) + dp[0]
i = 3 => 00(1)[1] => res[3] = 2 = (1) + dp[1]

offset = 4
i = 4 => 0(1)[00] => res[4] = 1 = (1) + dp[0]
i = 5 => 0(1)[01] => res[5] = 2 = (1) + dp[1]
i = 6 => 0(1)[10] => res[6] = 2 = (1) + dp[2]
i = 7 => 0(1)[11] => res[7] = 3 = (1) + dp[3]

offset = 8
i = 8 = (1)[000]   => res[8] = 1 = (1) + dp[0]
```

## C_1 Dynamic Programmin + Bitwise
```
result[i] = result[i >> 1]        + (i & 1);
          = bit 1 ~ heightest bit + bit 0 (last bit)

[X X ... X X X] (X)
result[i >> 1] => [X X ... X X X]
(i & 1) => (X)
```

## C_3 C_4 Dynamic Programmin + Bitwise
```
result[i] = last bit 1 + last bit 1 ~ heightest bit (exclude last bit 1)
          = 1          + result[last bit 1 ~ heightest bit]

result[i] = 1 + result[i - (i & -i)]
i - (i & -i) => delete last bits 1

result[i] = 1 + result[i & (i - 1)]
i & (i - 1) => delete last bits 1
```
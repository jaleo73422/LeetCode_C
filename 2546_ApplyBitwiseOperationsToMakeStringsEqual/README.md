# 2572. Count the Number of Square-Free Subsets

## _1, _2, _3
```
a b =>
0 1 => 1 1
1 0 => 1 1 -> case1
(0 0 => 0 0)
1 1 => 1 0 -> case2

s[j] s[i] t[j]   t[i]
a    b    a ^ b  a | b
1    1    0      1 -> case2
0    1    1      1 -> case1

if (s[i], t[i]) = (1, 1) not exist
return false
but (1, 1) come from case1 (1, 0)
if ((1 in a) and (1 in b)) or (a equal to b)
return ture
```


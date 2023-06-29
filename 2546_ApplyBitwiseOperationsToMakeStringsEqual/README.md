# 2546. Apply Bitwise Operations to Make Strings Equal

## C_1 C_2 C_3 Bitwise
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

Case 1: s == target => return true
Case 2: if there are any bit1 exist in s 
        => change 0 to 1 or 1 to 0, 
        but if all change is 1 to 0 (target no any 1)
        => there is a 1 cann't change to 1 in s, 
        because others 1 is changed to 0, no any 1 can help it
```


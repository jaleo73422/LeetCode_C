# 1318. Minimum Flips to Make a OR b Equal to c

## C_1 Bitwise
```
a b c
1 0 1 => (a | b) == c
1 1 1 => (a | b) == c
0 0 0 => (a | b) == c

1 1 0 => (0 0) => 2 => (a ^ b)  == 0
0 0 1 => (0 1) => 1 => (a ^ b)  == 0
1 0 0 => (0 0) => 1 => (a ^ b)  == 1
```

```c
if((new_a | new_b) != new_c) {
    if(new_a ^ new_b) {  // (1 0 _) or (0 1 _)
        if(!new_c)  res++;  // (1 0 0) or (0 1 0)
    } else
        if(new_c)  res++;  // (0 0 1)
        else  res += 2;  // (1 1 0)
}
```

## C_2 C_3 Bitwise
```
Case 1: bit of c is 1 (0 | 1 or 1 | 0 or 1 | 1 = 1)
    1-1 both of a and b are 0 => flip 1 time
    1-2 at least one of a and b is 1 => no flip

Case 2: bit of c is 0 (0 | 0 = 0)
    2-1 both of a and b are 0 => no flip
    2-2 one of a and b is 1 => flip 1 time
    2-3 both of a and b are 1 => flip 2 time
```
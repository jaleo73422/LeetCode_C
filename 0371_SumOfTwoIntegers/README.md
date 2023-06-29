# 371. Sum of Two Integers

## _1 Bitwise
the program finish after no more carry <br/>
```c
while(b != 0) {
    int carry = (unsigned int) (a & b);  // line 1
    a = a ^ b;  // line 2
    b = carry << 1;  // line 3
}
```

```
Case 1: both of bit of a and bit of b are 1 => carry (linr 1, 3)
Case 2: (line 2)
    2 - 1 one of bit of a and bit of b is 1 => 0 + 1 = 1 (no carry)
    2 - 2 both of bit of a and bit of b are 0 => 0 + 0 = 0 (no carry)

```
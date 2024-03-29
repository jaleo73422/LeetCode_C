# 190. Reverse Bits
C_1 is similar to C_2
C_3 is similar to C_4

## C_1
```c
for(int i = 31;  i >= 0;  i--) {
    // A B C D E
    uint32_t tem = n << i;  // (D E) 0 0 0
    tem >>= 31;             // 0 0 0 0 (D)
    tem <<= i;              // 0 (D) 0 0 0
    res ^= tem;             // (E D) 0 0 0
    // or res |= tem;
}
```

```
<< >> <<
4  4  4   E 0 0 0 0
3  4  3   0 D 0 0 0
2  4  2   0 0 C 0 0
1  4  1   0 0 0 B 0
0  4  0   0 0 0 0 A
  |) or ^)
```

## C_2
```c
for(int i = 0; i < 32; i++) {
    // A B C D E
    n >>= i;         // 0 A B C D
    n &= 1;          // 0 0 0 0 D
    n <<= (31 - i);  // 0 D 0 0 0
    res |= n;        // E D 0 0 0
    // or res ^= n;
}
```

```
          E 0 0 0 0
          0 D 0 0 0
          0 0 C 0 0
          0 0 0 B 0
          0 0 0 0 A
|) or ^)
```

## C_3
```c
// A B C D E
if(n & 1)  res = 1;          // 0 0 0 0 E

for(int i = 1; i < 32; i++) {
    res <<= 1;                // 0 0 0 E 0
    if((n >> i) & 1)  res++;  // 0 0 0 0 D -> 0 0 0 E D
}
```

```
A B C D E
0 0 0 0 E
0 0 0 E D
0 0 E D C
0 E D C B
E D C B A
```

## C_4
```c
uint32_t res = 0;
for (int i = 0; i < 32; i++) {
    // A B C D E
    res <<= 1;     //    0 0 0 0 E -> 0 0 0 E 0
    res |= n & 1;  //              | (0 0 0 0 D) = 0 0 0 E D
    // or res ^= n & 1;
    n >>= 1;       // 0 0 A B C
}
```

```
A B C D E
0 0 0 0 E
0 0 0 E D
0 0 E D C
0 E D C B
E D C B A
```

## C_5 mask
```c
// do every 4 bits

for (int i = 0; i < 8; i++) {
    // ... A B C D E F G H
    tem = lookup[n & 0xF];  // 0 ...  0 0 0 0 D C B A
    res <<= 4;              // 0 ...  H G F E 0 0 0 0
    res |= tem;             // 0 ...  H G F E D C B A
    // or res ^= tem;

    n = n >> 4;
}
```

```
all condition of 4 bits n = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};

reverse of 4 bits n = {
    0x00, 0x08, 0x04, 0x0C, 0x02, 0x0A, 0x06, 0x0E,
    0x01, 0x09, 0x05, 0x0D, 0x03, 0x0B, 0x07, 0x0F
};

ABCD EFGH IJKL

0000 0000 LKJI
0000 LKJI HGFE
LKJI HGFE DCBA
```

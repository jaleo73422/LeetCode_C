# 1318. Minimum Flips to Make a OR b Equal to c

## _1 Floyd Cycle Detection Algorithm
```
    a b c
    1 0 1 => (a | b) == c
    1 1 1 => (a | b) == c
    0 0 0 => (a | b) == c


    1 1 0 => (0 0) => 2 => (a ^ b)  == 0
                           (a ^ b) | c == 0
    0 0 1 => (0 1) => 1 => (a ^ b)  == 0
                           (a ^ b) | c == 1
    1 0 0 => (0 0) => 1 => (a ^ b)  == 1
                           (a ^ b) & c == 0
```


## _2 

## _3 
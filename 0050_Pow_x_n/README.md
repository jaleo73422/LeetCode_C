# 50. Pow(x, n)

## _1 Square and multiply algorithm

## _2 
```
use tem = n to avoid
runtime error: negation of -2147483648 cannot be represented in type 'int';
 cast to an unsigned type to negate this value to itself.

tem /= 2;

if(n < 0) {
    x = 1 / x;
    tem = -tem;
}

2147483647 is the largest positive integer.
cannot convert -2147483648 to positive number of same datatype.

if n is negative, there is different between /2 and >>1
```

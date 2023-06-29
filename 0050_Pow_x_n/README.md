# 50. Pow(x, n)

## C_1 Square and multiply algorithm
explaination 1: <br/>
```
step 1: Convert the exponent to binary.
step 2:
    Each 0 requires a square
    Each 1 requires a square and then a multiply

ex.
Input: x = 2.00000, n = 10

10 = 1010

<pf> ?
step 1:
2^1 * 2^0 = 2^1
  (Square) 2^1 * 2^1 = 2^2
  (Square) 2^2 * 2^2 = 2^4
  (Square) 2^4 * 2^4 = 2^8
(Multiply) 2^8 * 2^2 = 2^10

step 2:
3 * (Square) and 1 *(Multiply) reset
2^1 * 2^0 = 2^1
  (Square) 2^1 * 2^1 = 2^2
  (Square) 2^2 * 2^2 = 2^4
(Multiply) 2^4 * 2^1 = 2^5
  (Square) 2^5 * 2^5 = 2^10

1
  (Square) 2^0 * 2^0 = 2^0
(Multiply) 2^0 * 2^1 = 2^1
0
  (Square) 2^1 * 2^1 = 2^2
1
  (Square) 2^2 * 2^2 = 2^4
(Multiply) 2^4 * 2^1 = 2^5
0
  (Square) 2^5 * 2^5 = 2^10

equal to

1 -> 2
0 -> 2 * 2 = 2^2
1 -> 2^2 * 2^2 * 2^1 = 2^5
0 -> 2^5 *2^5 = 2^10
```

explaination 2: <br/>
```
Input: x = 2.00000, n = 10

10 is even
10 / 2 = 5
=> 2^10 = 2^5 * 2^5

5 is odd
5 / 2 = 2
=> 2^5 = 2^2 * 2^2 * 2

2 is even
2 / 2 = 1
=> 2^2 = 2^1 * 2^1
```

```
if(n == 1)  return x;
can be deleted
```
[https://ebckurera.wordpress.com/2018/02/24/square-and-multiply-algorithm/](https://ebckurera.wordpress.com/2018/02/24/square-and-multiply-algorithm/)

## C_2
```
ex.
Input: x = 2.00000, n = 10

 10 = 1010
pow = 8421
res = 2^8 * 2^2

use tem = n to avoid
runtime error: negation of -2147483648 cannot be represented in type 'int';
cast to an unsigned type to negate this value to itself.

tem = n / 2;

if(n < 0) {
    x = 1 / x;
    tem = -tem;
}

2147483647 is the largest positive integer.
cannot convert -2147483648 to positive number of same datatype.

if n is negative, there is different between /2 and >>1
```

## C_3 Square and multiply algorithm
```
same as C_1

else return res * res / x;
=> process n is negative odd integer
```

## C_4 Square and multiply algorithm
same as C_1 <br />
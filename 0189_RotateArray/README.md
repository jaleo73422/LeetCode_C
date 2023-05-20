# 189. Rotate Array

## _1 Temporary array
Time complexity: O(N) <br/>
Auxiliary Space: O(N) <br/>

## _2 Rotate one by one
TLE <br/>
Time Complexity: O(N * k) <br/>
Auxiliary Space: O(1) <br/>

## _3 Block swap algorithm by iteration
Time Complexity: O(N) <br/>
Auxiliary Space: O(1) <br/>

can also implement by recursive: <br>
Time Complexity: O(N) <br/>
Auxiliary Space: O(log N) <br/>

```
k = 3
1 2 3 4 5 6 7

A: f
B: s

(1 2 3 4)  (5 6 7)
A          B

((1 2 3) 4) (5 6 7)
A           B

(5 6 7) 4 (1 2 3)

[5 6 7] (4) (1 2 3)
        A   B

[5 6 7] (4) (1 2 (3))
        A   B

[5 6 7] (3) 1 2 (4)


[5 6 7] (3) (1 2) [4]
        A   B

[5 6 7] (3) (1 (2)) [4]
        A   B

[5 6 7] (2) 1 (3) [4]

[5 6 7] (2) (1) [3 4]
        A   B

[5 6 7] 1 2 [3 4]
```

```
edge case:
int nums[] = {-1};
int k = 2;

right answer:
k %= numsSize;
if(k == 0 || k == numsSize)  return ;

wrong answer:
if(k == 0 || k == numsSize)  return ;
k %= numsSize;

```

## _4 Juggling algorithm

## _5 Reversal algorithm
Time Complexity: O(N) <br/>
Auxiliary Space: O(1) <br/>

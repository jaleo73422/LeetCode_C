# 189. Rotate Array

## C_1 Temporary array
Time complexity: O(N) <br/>
Auxiliary Space: O(N) <br/>

```
Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3

step 1:
res = {5, 6, 7}

step 2:
res = {5, 6, 7, 1, 2, 3, 4}
```

## C_2 Rotate one by one
TLE <br/>
Time Complexity: O(N * k) <br/>
Auxiliary Space: O(1) <br/>

```
Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3

res = {7, 1, 2, 3, 4, 5, 6}
res = {6, 7, 1, 2, 3, 4, 5}
res = {5, 6, 7, 1, 2, 3, 4}
```

## C_3 Block swap algorithm by iteration
Time Complexity: O(N) <br/>
Auxiliary Space: O(1) <br/>

can also implement by recursive: <br>
Time Complexity: O(N) <br/>
Auxiliary Space: O(log N) <br/>

```
1) Divide the array into two parts, A = arr[0 ... k] and B = arr[k + 1 ... n - 1].
2) While size of A is not equal to size of B, do this:
2.1 If size of A is smaller than B, swap A with a subarray of B of size equal to that of A and which is not adjacent to A.
2.2 Else(size of B is smaller than A), swap B with a subarray of A of size equal to that of A and which is not adjacent to B.
3) Swap A and B
```

```
Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3

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

## C_4 Juggling algorithm
```
step 1:
find gcd of k and numsSize

each (gcd) right shift cycle

Input: nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}, k = 3

round 1:
1 4 7 => 7 1 4
nums = {7, 2, 3, 1, 5, 6, 4, 8, 9}

round 2:
2 5 8 => 8 2 5
nums = {7, 8, 3, 1, 2, 6, 4, 5, 9}


round 2:
3 6 9 => 9 3 6
nums = {7, 8, 9, 1, 2, 3, 4, 5, 6}
```

## C_5 Reversal algorithm
Time Complexity: O(N) <br/>
Auxiliary Space: O(1) <br/>

```
Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3

step 1:
reverseArray(nums, 0, numsSize - k - 1);
nums = {4, 3, 2, 1, 5, 6, 7}

step 2:
reverseArray(nums, numsSize - k, numsSize - 1);
nums = {4, 3, 2, 1, 7, 6, 5}

step 3:
reverseArray(nums, 0, numsSize - 1);
nums = {5, 6, 7, 1, 2, 3, 4}
```
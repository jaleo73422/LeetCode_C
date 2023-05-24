# 287. Find the Duplicate Number

## 1 Floyd Cycle Detection Algorithm

```
nums[] = {3, 1, 3, 4, 2}

-> 3 ->  4 -> 2 ->

nums[] = {2, 4, 1, 3, 1}

2 -> 1 -> 4 ->
       ^

nums[] = {2, 6, 4, 1, 3, 5}

2 -> 4 -> 3 -> 1 -> 6 -> 5 ->
                      ^

142. Linked List Cycle II
```

[https://englishandcoding.pixnet.net/blog/post/30106939-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D287.-find-the-duplicate-number](https://englishandcoding.pixnet.net/blog/post/30106939-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D287.-find-the-duplicate-number)

## _2 Indexing sort
Does not meet the condition: "You must solve the problem without modifying the array nums and use only constant extra space." <br/>

```
index:     [0  1  2  3  4]
nums:      [1, 3, 4, 2, 2]
sort nums: [1, 2, 3, 4, 2]
```

## _3 Indexing sort
Does not meet the condition: "You must solve the problem without modifying the array nums and use only constant extra space." <br/>

```
nums:       [1, 3, 4, 2, 2]
index:      [0  1  2  3  4]
times nums: [0, 1, 2, 1, 1]
```

```
int sort_arr[numsSize];
memset(sort_arr, 0, numsSize * sizeof(sort_arr[0]));

or

int* sort_arr = (int*) calloc(numsSize, sizeof(int));
```

## _4 Sort
Does not meet the condition: "You must solve the problem without modifying the array nums and use only constant extra space." <br/>

## _5 Binary search

```
1 3 4 2 2 
numsSize = 5
nums(duplicated number) > nums(missing numbers)

1 2 3 4
^ ^     ^
L M   R

if(nums(<=M) > M) => duplicated number in [L, M]
1 (2) 3 4
1 1 2 3 4 or 1 2 2 3 4

if(nums(<=M) == M) => no missing number in [1, L], duplicated number in [M + 1, R]
1 (2) 3 4
1  2 3 3 4 or 1 2 3 4 4

if(nums(<=M) < M) => exist missing number in [1, L], duplicated number in [M + 1, R]
1 (2) 3 4
2 3 4 4 4 or 2 3 3 3 4
```

## _6 Bitwise

```
nums = {1, 3, 4, 2, 2}
nums: 0 ~ 4
n: 1 ~ 4

                1 = 001
                2 = 010
                3 = 011
                4 = 100
bit_1_n =       122

                2 = 010
bit_1_nums = 132 

              res = 010
```

[https://hackmd.io/@meyr543/rkSRWnXPK](https://hackmd.io/@meyr543/rkSRWnXPK)

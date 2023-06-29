# 287. Find the Duplicate Number

## C_1 Floyd Cycle Detection Algorithm

```
customize a route

nums[] = {3, 1, 3, 4, 2}

3 ->  4 -> 2
^__________|

slow: 3 4 2 3
fast: 3 2 4 3


nums[] = {2, 4, 1, 3, 1}

2 -> 1 -> 4
^_________|

slow: 2 1 4
fast: 2 4 4

142. Linked List Cycle II
```

[https://englishandcoding.pixnet.net/blog/post/30106939-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D287.-find-the-duplicate-number](https://englishandcoding.pixnet.net/blog/post/30106939-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D287.-find-the-duplicate-number)

## C_2 Indexing sort
Does not meet the condition: "You must solve the problem without modifying the array nums and use only constant extra space." <br/>

```
index:     [0  1  2  3  4]
nums:      [1, 3, 4, 2, 2]
target:    [1, 2, 3, 4, _]
sort nums: [1, 2, 3, 4, 2]

target[i] = i + 1

nums[i] != i + 1 => check if nums[i] = i + 1
nums[i] != nums[nums[i] - 1] => check if nums[i]'s position haved right value
                             => 1) right => continue roop
                             => 2) wrong => put nums[i] to right position
```

## C_3 Indexing sort
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

## C_4 Sort
Does not meet the condition: "You must solve the problem without modifying the array nums and use only constant extra space." <br/>

## C_5 Binary search (CSE)

```
nums:  [1, 3, 4, 2, 2]
m:     [1  2  3  4]
count: [1, 3 ...]
```

## C_6 Bitwise

```
nums = {1, 3, 4, 2, 2}
nums: 0 ~ 4
n: 1 ~ 4

                1 = 001
                2 = 010
                3 = 011
                4 = 100
bit_1_n =           122 <= [1, 2, 3, 4]

                2 = 010
bit_1_nums =        132 <= [1, 2, 3, 4, 2] 

              res = 010
```

[https://hackmd.io/@meyr543/rkSRWnXPK](https://hackmd.io/@meyr543/rkSRWnXPK)

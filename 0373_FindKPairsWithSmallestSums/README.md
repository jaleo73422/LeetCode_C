# 373. Find K Pairs with Smallest Sums

*returnColumnSizes ? <br/>

## C_1 Binary search (CSE)
```
Step 1: find the Kth smallest sum (target_sum)
Step 2: find k pair
    2-1 find the pair which sum less than target_sum
    2-2 find the pair which sum equal to target_sum, 
        if choose all pair sum equal to target_sum, 
        maybe let numbers of pair > k
```

## Cpp_1 Priority queue
```
Step 1: put (0, 0, sum) = (0 ~ k - 1, 0, sum) priority queue
Step 2: choose a min sum (i, j) from priority queue, 
        and put a pair (i, j + 1) in priority queue
```

## Cpp_2 Priority queue
```
Step 1: choose (0, 0)
Step 2: choose a min sum (i, j) from priority queue, 
        and put the pairs (i + 1, j) and (i, j + 1) 
        that have never been choosen in priority queue
```
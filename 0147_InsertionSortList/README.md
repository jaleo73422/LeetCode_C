# 147. Insertion Sort List

## _1 
```
reverse_head -> cur_node -> node3 -> node4 -> NULL

NULL <- reverse_head
cur_node -> node3 -> node4 -> NULL

step 1: edge case
only one node linkrd list

step 2:
NULL <- (3) <- nodex <- (2) <- reverse_head <- (1)
cur_node -> node3 -> node4 -> NULL


pre = reverse_head

NULL <- 4      2 -> 1 -> 3
        ^      ^
        pre    cur

round 1:
4  ->  2 -> 1 -> 3
^           ^
pre         cur

2 -> 4  ->  1 -> 3
     ^      ^
     pre    cur

2 <- 4      1 -> 3
     ^      ^
     pre    cur

round 2:
2 <- 4      1 -> 3
     ^      ^
     pre    cur

2 <- 4    1 -> 3
     ^         ^
     pre       cur

1 <- 2 <- 4       3
          ^       ^
          pre     cur

step 3: reverse linked list
```

##　_2
```
round 1:
INT_MIN -> NULL
^
dummy
pre

4 -> 2 -> 1 -> 3 -> NULL
^    ^
cur  next


INT_MIN -> 4 -> NULL
^
dummy
pre

2 -> 1 -> 3 -> NULL
^
next
cur

combine (1), (2), (3) of solution 1
find a node that insert node in its next
start from dummy (before head node)
pre < cur < pre_next
```
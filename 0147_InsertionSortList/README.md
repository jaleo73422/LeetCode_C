# 147. Insertion Sort List

## C_1 Linked list (reverse)
```
reverse_head -> cur_node -> node3 -> node4 -> NULL

NULL <- reverse_head
cur_node -> node3 -> node4 -> NULL

step 1: edge case
     only one node linkrd list

step 2:
     NULL <- (3) <- node <- (2) <- reverse_head <- (1)
     cur_node -> node3 -> node4 -> NULL


     pre = reverse_head = 4

     NULL <- 4      2 -> 1 -> 3 -> NULL
             ^      ^
             in     cur

     round 1: case 3
          4 -> 2 -> NULL

          1 -> 3 -> NULL
          ^
          cur

     round 2: case 3
          2-1
               4 -> 2 -> NULL

               1 -> 3 -> NULL
               ^    ^
               in   cur

          2-2
               4 -> 2 -> 1 -> NULL

               3 -> NULL
               ^
               cur
     
     round 3: case 2
          3-1
               4 -> 2 -> 1 -> NULL

               3 -> NULL
               ^    ^
               in   cur
          3-2
               4 -> 3 -> 2 -> 1 -> NULL

               NULL
               ^
               cur


step 3: reverse linked list
4 -> 3 -> 2 -> 1 -> NULL
=> 1 -> 2 -> 3 -> 4 -> NULL
```

##　C_2 Linked list
```
P -> A
C -> N -> A

1)
C -> B
N -> A
P -> A

2)
P -> N -> A
C -> B
```

```
round 1:
     1-1
          INT_MIN -> NULL
          ^
          dummy
          pre

          4 -> 2 -> 1 -> 3 -> NULL
          ^    ^
          cur  next

     1-2
          INT_MIN -> 4 -> NULL
          ^
          dummy
          pre

          2 -> 1 -> 3 -> NULL
          ^
          next
          cur

round 2:
     2-1
          INT_MIN -> 4 -> NULL
          ^
          dummy
          pre

          2 -> 1 -> 3 -> NULL
          ^    ^
          cur  next

     2-2
          INT_MIN -> 2 -> 4 -> NULL
          ^
          dummy
          pre

          1 -> 3 -> NULL
          ^
          cur

round 3:
     INT_MIN -> 1 -> 2 -> 4 -> NULL

round 4:
     INT_MIN -> 1 -> 2 -> 3 -> 4 -> NULL
```
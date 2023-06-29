# 61. Rotate List

## C_1
```
Rotate (k % llSize) times directly

A -> B -> C -> D   ->   E -> NULL
^              ^        ^
new_head       secLast  last

rotate
E -> A -> B -> C   ->   D -> NULL
^                       ^
new_head                secLast
last
```

## C_2
```
find whole part of rotate
rotate 1 time

ex.
1 -> 2 -> 3 -> 4 -> 5 -> NULL
k = 2
1 -> 2 -> 3 -> (4 -> 5) -> NULL
rotate => (4 -> 5) -> 1 -> 2 -> 3 -> NULL

k = 2
A -> B -> C -> D -> E -> NULL
                    ^
                    tail

step 1: Check edge case

if(!head || !(head -> next) || k == 0)  return head;
if(rotateTime == 0)  return head;

step 2: Find new tail node

A -> B -> C -> D ->   E -> NULL
          ^           ^
          new_tail    tail

step 3: Find new head node

A -> B -> C ->  NULL
                D ->   E -> NULL
          ^            ^
          new_tail     tail


step 4: Connect two nodes

D -> E -> A -> B -> C ->  NULL     
     ^              ^
     tail           new_tail


```
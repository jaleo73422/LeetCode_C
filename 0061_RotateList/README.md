# 57. Rotate List

## _1
```
Rotate (k % llSize) times directly

A -> B -> C -> D   ->   E -> NULL
^              ^        ^
new_head       secLast  last
```

## _2
```
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
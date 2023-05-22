# 19. Remove Nth Node From End of List

## _1 

## _2 
```
head -> node2 -> node3 -> node4 -> node5 -> NULL
n = 2

dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
^
first
second

dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
                      ^
                      second

dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
                                     ^
                                     second
                      ^
                      first
                           ^
                           tem
```

```
head -> node2 -> node3 -> node4 -> node5 -> NULL
n = 5

dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
^
first
second

dummy -> head -> 2 -> 3 -> 4 -> 5 -> NULL
                                     ^
                                     second
^
first
         ^
         tem
```
# 19. Remove Nth Node From End of List

## _1 

## _2 Floyd Cycle Detection Algorithm
fast is n steps ahead of slow <br/>
fast run n steps first slow and then start <br/>

fast is second <br/>
slow is first <br/>

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
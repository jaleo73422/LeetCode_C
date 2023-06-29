# 19. Remove Nth Node From End of List

## C_1 Linkedlist

## C_2 Floyd Cycle Detection Algorithm
At the beginning fast is ahead of slow n steps, <br/>
fast and slow move together <br/>
when fast reaches the end (NULL), <br/>
slow will be behind fast n steps <br/>
=> slow is target

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
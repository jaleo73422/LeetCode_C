# 328. Odd Even Linked List

```
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

1 -> 3 -> 5 -> NULL
2 -> 4 -> 6 -> NULL

1 -> 3 -> 5 -> 2 -> 4 -> 6 -> NULL
```

## C_1 Linked list
```
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
          ^
          tem

round 1:
1 -> 3 -> (4 -> 5 -> 6 -> NULL)
2 -> (3 -> 4 -> 5 -> 6 -> NULL)
           ^
           tem

round 2:
1 -> 3 -> (4 -> 5 -> 6 -> NULL)
2 -> 4 -> (5 -> 6 -> NULL)
           ^
           tem

round 3:
1 -> 3 -> 5 -> (6 -> NULL)
2 -> 4 -> (5 -> 6 -> NULL)
                ^
                tem

round 4:
1 -> 3 -> 5 -> (6 -> NULL)
2 -> 4 -> 6 -> (NULL)
                ^
                tem


if number of linked list node is odd
1 -> 2 -> 3 -> 4 -> 5 -> NULL

1 -> 3 -> 5 -> (NULL)
2 -> 4 -> (5 -> NULL)

2 -> 4 -> NULL
```

## C_2 Linked list
```
ex 1.
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

round 1:
1 -> 3 -> (4 -> 5 -> 6 -> NULL)
2 -> 4 -> (5 -> 6 -> NULL)

round 2:
1 -> 3 -> 5 -> (6 -> NULL)
2 -> 4 -> 6 -> (NULL)

ex 2.
1 -> 2 -> 3 -> 4 -> 5 -> NULL

round 1:
1 -> 3 -> (4 -> 5 -> NULL)
2 -> 4 -> (5 -> NULL)

round 2:
1 -> 3 -> 5 -> (NULL)
2 -> 4 -> NULL
```

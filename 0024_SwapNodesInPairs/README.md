# 24. Swap Nodes in Pairs

## C_1
This solution modifies the values in the list's nodes. <br/>

## C_2
dummy is a node. <br/>
pre is a pointer to dummy. <br/>

```
pre -> f -> s -> node

step 1:
pre -> s -> node
f -> s -> node

step 2:
pre -> s -> node
f -> node

step 3:
pre -> s -> f -> node

step 4:
s -> f -> node
     ^
     pre


pre -> A -> B -> C -> D -> NULL
       f    s

step 1:
pre -> B(s) -> C -> D -> NULL
       A(f) -> B -> C -> D -> NULL

step 2:
pre -> B(s) -> C -> D -> NULL
A(f) -> C -> D -> NULL

step 3:
pre -> B(s) -> A(f) -> C -> D -> NULL

step 4:
B(s) -> A(f) -> C -> D -> NULL
        ^
        pre
```
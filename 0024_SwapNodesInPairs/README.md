# 24. Swap Nodes in Pairs

## _1
This solution modifies the values in the list's nodes. <br/>

## _2
dummy is a node. <br/>
pre is a pointer to dummy. <br/>

```
pre -> A -> B -> C -> D -> NULL
       f    s

step 1:
pre -> B -> C -> D -> NULL
       A -> C -> D -> NULL

step 2:
pre -> B -> A -> C -> D -> NULL

step 3:
B -> A -> C -> D -> NULL
     ^    ^    ^
     pre  f    s
```
# 92. Reverse Linked List II

## C_1 Linked list (revere)
```
head -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
left = 3, right = 5

step 1:
front_tail -> head -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
              ^
              new_head

head -> 2      ->       3 -> 4 -> 5 -> 6 -> NULL
        ^               ^
        front_tail      new_head
                        (reverse_tail)

step 2: reverse
head -> 2 ->
        ^   
        front_tail

NULL <- 3    <-    4   <-   5            6 -> NULL
        ^                   ^            ^
        new_head            pre_node     current_node
        reverse_tail

step 3:
head -> 2 -> 5 -> 4 -> 3 -> 6
             ^
             pre_node
```

## C_2 
```
P -> C -> N -> A
1)
P -> C -> A
N -> A

2)
P -> C -> A
N -> C

3)
P -> N -> C -> A
```

```
left = 3, right = 5
2 -> 3 -> 4 -> 5 -> 6
pre_node (2) and current_node (3) don’t change value

(2) -> (3) -> 4 -> 5 -> 6

step 1: remove next_node
current_node -> next = next_node -> next
(2) -> (3) -> 5 -> 6
remove 4

step 2: add next_node
next_node -> next = pre_node -> next (4 -> 3)
pre_node -> next = next_node (2 -> 4)
(2) -> 4 -> (3) -> 5 -> 6
add 4

(2) -> (3) -> 4 -> 5 -> 6
(2) -> 4 -> (3) -> 5 -> 6
(2) -> 5 -> 4 -> (3) -> 6
```

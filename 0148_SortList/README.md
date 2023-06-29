# 148. Sort List

## C_1 Merge sort - top down
```C
if(slide1 == head1) {
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node -> val = slide1 -> val;
    slide1 = slide1 -> next;
    cur_node -> next = new_node;
    cur_node = cur_node -> next;
}

// avoid to appear cycle
```

put smaller value of the two linked list in new node until one of them is end (NULL) <br/>
then put the other linked list behind the merged list <br/>
note that cycle caused by connecting head node <br/>

## C_2 Merge sort - top down
replace C_1 with dummy node to connect the other linked list behind the merged list <br/>

## C_3 Merge sort - top down
recursion in merge function <br/>

## C_4 Merge sort - top down
merge in head1 <br/>
if merged node in head2, swap the nodes <br/>

##　C_5 Merge sort - bottom up
```
2 -> 4 -> 7 -> 1 -> 3 -> 6 -> 5 -> 9
step 1: (2 -> 4) -> (1 -> 7) -> (3 -> 6) -> (5 -> 9)
step 2: (1 -> 2 -> 4 -> 7) -> (3 -> 5 -> 6 -> 9)
step 4: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 9
```
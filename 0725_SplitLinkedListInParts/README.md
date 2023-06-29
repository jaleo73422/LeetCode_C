# 725. Split Linked List in Parts

## C_1 Linked list
```
case 1: llSizes < k
(llSizes parts) * 1
(k - llSizes parts) * 0 (NULL)

case 2: llSizes == k
(k parts) * 1

case 3: llSizes > k
3.1 llSizes % k == 0
    (k parts) * (llSizes / k)
3.2 llSizes % k != 0
    ((llSizes % k) parts) * (llSizes / k + 1)
    ((k - llSizes % k) parts) * (llSizes / k)
```

## C_2 Linked list
simplify solution 1 <br/>
combine 3 case of solution 1 <br/>

```
(extraCount parts) * (baseCount + 1)
((k - extraCount) parts) * (baseCount)
```

## C_3 Linked list
```
dummy node + length array + memset()

if head == NULL => memset(result_node, 0, sizeof(struct ListNode*) * k)
=> return result_node

memset(length, 0, sizeof(int) * k);
or
int length[k] = {0};
```
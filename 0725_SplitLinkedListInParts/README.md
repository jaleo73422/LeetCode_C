# 725. Split Linked List in Parts

## _1 
```
case 1: llSizes < k
llSizes parts * arr[1]
k - llSizes parts * arr[0]

case 2: llSizes == k
k parts * arr[1]

case 3: llSizes > k
3.1 llSizes % k == 0
    k parts * arr[llSizes / k]
3.2 llSizes % k != 0
    (llSizes % k) parts * arr[llSizes / k + 1]
    (k - llSizes % k) parts * arr[llSizes / k]
```

## _2 
simplify solution 1 <br/>
combine 3 case of solutions <br/>
```
baseCount: element numbers of no+1 parts
count: element numbers
    +1: count++ = no+1++ = baseCount++
    no+1: baseCount

extraCount: parts numbers of +1
k - extraCount: parts numbers of no+1
```

```
extraCount parts * arr[baseCount + 1]
+ (k - extraCount) parts * arr[baseCount]
```

## _3 
```
dummy node + length array + memset()

if head == NULL => memset(result_node, 0, sizeof(struct ListNode*) * k)
=> return result_node

memset(length, 0, sizeof(int) * k);
or
int length[k] = {0};
```
# 56. Merge Intervals
```c=
/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * The parameter intervalsColSize can be ignored.
*/

*returnColumnSizes = malloc(sizeof(int) * intervalsSize);
*returnSize = 0;
retrn result[*returnSize]
```

*nums = nums[0] <br/>
**nums = *nums[0] = nums[0][0] <br/>

## C_1
```
... pre, intervals[i] ...

case 1: two internals overlap
        => intervals[i][0] <= pre[1]
pre:       [  pre  ] ... ]
intervals: [  ...  [ ... ]
=>    pre: [  ...        ]

case 2: two internals no overlap
        => intervals[i][0] > pre[1]
pre:       [  pre  ]
intervals:          [  ...  ]
=>    res: [  ...  ]

```

## C_2
```
example 1:
intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
new_array = [[1, 1], [3, -1], [2, 1], [6, -1], [8, 1], [10, -1], [15, 1], [18, -1]]
-> new_array = [[1, 1], [2, 1], [3, -1], [6, -1], [8, 1], [10, -1], [15, 1], [18, -1]]

example 2:
intervals = [[1, 4], [4, 5]]
new_array = [[1, 1], [4, 1], [4, -1], [5, -1]]
``` 
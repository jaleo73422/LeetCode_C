# 137. Single Number II

## C_1 Bitwise
```
Step 1: put nums[i] in ones
Step 2: if nums[i] has existed in ones => cancel step 1
ones = ones ^ nums[i]

Step 3: if nums[i] has existed in twos => cancel step 1
ones = ones & ~twos

Step 4: do the same as the ones' 3 steps for twos
twos = (twos ^ nums[i]) & ~ones


case 1: first appear
nums[i] not in ones and twos => put in ones

case 2: second appear
nums[i] in ones => remove from ones and put in twos

case 3: thied appear
nums[i] in twos => remove from twos
```

## C_2 Bitwise
bit1's sum of each bit % 3 = bit of single number <br/>

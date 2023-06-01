# 137. Single Number II

## _1 Bitwise
```
ones = (ones ^ nums[i]) & ~twos;
twos = (twos ^ nums[i]) & ~ones;

case 1:
nums[i] not in ones and twos => put in ones
ones = (a ^ nums[i]) & ~b = (1 & 1) = a ^ nums[i]
twos = (b ^ nums[i]) & ~ones = (1 & 0) = b

case 2:
nums[i] in ones => remove from ones and put in twos
ones = (a ^ nums[i]) & ~b = (0 & 1) = a
twos = (b ^ nums[i]) & ~ones = (1 & 1) = b ^ nums[i]

case 3:
nums[i] in twos => remove from twos
ones = (a ^ nums[i]) & ~b = (1 & 0) = a
twos = (b ^ nums[i]) & ~ones= (0 & 1) = b

```

## _2 Bitwise
sum of each bit % 3 = bit of single number <br/>

# 242. Valid Anagram
## _1 Sort array

## _2 _4 Hash table
compare
_2
```c
for(int i = 0; i < tSize; i++) {
    hash[t[i] - 'a']--;

    if(hash[t[i] - 'a'] < 0)
        return 0;
}
```

value of hash table still work
only use "hash[t[i] - 'a'] < 0"

and

_4
```c
for(int i = 0; i < sSize; i++) {
    hash[s[i] - 'a']++;
    hash[t[i] - 'a']--;
}

for(int i = 0; i < tSize; i++)
    if(hash[t[i] - 'a'] != 0)
        return 0;
```

becaus tSize == sSize
so:
hash[in s but not in t] > 0
hash[in t but not in s] < 0

The following options are correct
1) if(hash[t[i] - 'a'] != 0)
2) if(hash[s[i] - 'a'] != 0)
3) if(hash[t[i] - 'a'] < 0)
4) if(hash[s[i] - 'a'] > 0)

## _3 Array

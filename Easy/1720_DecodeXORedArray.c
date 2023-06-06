#include <stdio.h>
#include <stdlib.h>

int* decode(int* nums, int n, int f) {
    int* res = malloc((n + 1) * sizeof(int));
    res[0] = f;
    
    for(int i = 1; i < n + 1; i++)
        res[i] = res[i - 1] ^ nums[i - 1];
    
    return res;
}

void main() {
}
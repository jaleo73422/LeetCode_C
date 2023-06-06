#include <stdio.h>
#include <stdbool.h>

bool hasAlternatingBits(int n){
    int bit = n & 1;
    n >>= 1;
    
    while(n) {
        if(bit == (n & 1))  return 0;
        bit = !bit;
        n >>= 1;
    }
    
    return 1;
}

void main() {
}
#include <stdio.h>

int hammingDistance(int x, int y) {
    int n = x ^ y;
    int count = 0;
    
    while(n > 0) {
        if(n & 1) count++;
        n >>= 1;
    }
    
    return count;
}

int main() {
   return 0;
}
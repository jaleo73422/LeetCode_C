#include <stdio.h>

int binaryGap(int n) {
    int res = 0, distance = 1;
    int lastBit1 = n & (-n);
    
    while(lastBit1) {
        n >>= 1;
        lastBit1 >>= 1;
    }
    
    while(n) {
        if(n & 1) {
            res = distance > res ? distance : res;
            distance = 0;
        }
        
        distance++;
        n >>= 1;
    }
    
    return res;
}

void main() {
}
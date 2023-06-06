#include <stdio.h>

int binaryGap(int n) {
    int res = 0;
    
    for(int i = -32; n != 0; n >>= 1, i++)
        if(n & 1) {
            res = i > res ? i : res;
            i = 0;
        }

    return res;
}

void main() {
}
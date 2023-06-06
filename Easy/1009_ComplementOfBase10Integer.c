#include <stdio.h>

int bitwiseComplement(int n) {
    unsigned int highBit1 = 1;
    
    for(int i = 31; i >= 0; i--)
        if(n & (highBit1 << i)) {
            highBit1 <<= i;
            break;
        }

    return (~n) & (highBit1 - 1);
}

void main() {
}
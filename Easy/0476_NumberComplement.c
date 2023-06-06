#include <stdio.h>

int findComplement(int num) {
    unsigned int highBit1 = 1;
    
    for(int i = 31; i >= 0; i--)
        if(num & (highBit1 << i)) {
            highBit1 <<= i;
            break;
        }

    return (~num) & (highBit1 - 1);
}

void main() {
}
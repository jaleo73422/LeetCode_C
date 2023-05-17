#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;

    if(n & 1)  res = 1;

    for(int i = 1; i < 32; i++) {
        res <<= 1;
        if((n >> i) & 1)  res++;
    }
    
    return res;
}

int main() {
    // example 1
    // output = 964176192 (00111001011110000010100101000000)
    // uint32_t num = 43261596; // 00000010100101000001111010011100

    // example 2
    // output = 3221225471 (10111111111111111111111111111111)
    uint32_t num = 4294967293; // 11111111111111111111111111111101

    printf("%u \n", reverseBits(num));
    return 0;
}
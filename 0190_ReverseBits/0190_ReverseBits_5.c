#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    static const uint8_t lookup[] = {
        0x00, 0x08, 0x04, 0x0C, 0x02, 0x0A, 0x06, 0x0E,
        0x01, 0x09, 0x05, 0x0D, 0x03, 0x0B, 0x07, 0x0F
    };
    
    uint32_t res = 0;
    
    for(int i = 0; i < 8; i++) {
        res = (res << 4) | lookup[n & 0xF];
        n = n >> 4;
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
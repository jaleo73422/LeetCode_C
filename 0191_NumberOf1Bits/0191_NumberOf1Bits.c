#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int count = 0;

    while(n) {
        count++;
        n &= n - 1;
    }

    return count;
}


int main() {
    return 0;
}
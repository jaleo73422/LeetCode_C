#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
}

int main() {
   return 0;
}
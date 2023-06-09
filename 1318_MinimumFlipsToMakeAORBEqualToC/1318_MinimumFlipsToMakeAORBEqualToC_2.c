#include <stdio.h>

int minFlips(int a, int b, int c) {
    int res = 0;

    while(a || b || c) {
        if(c & 1)  res += 1 - ((a | b) & 1);
        else  res += (a & 1) + (b & 1);

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
   
    return res;
}


void main() {
    // example 1
    // output = 3
    // int a = 2, b = 6, c = 5;

    // example 2
    // output = 1
    // int a = 4, b = 2, c = 7;

    // example 3
    // output = 0
    int a = 1, b = 2, c = 3;

    printf("%d \n", minFlips(a, b, c));
}
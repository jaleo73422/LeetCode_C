#include <stdio.h>

int getSum(int a, int b){
    while(b!=0){
        int carry = (unsigned int) (a & b) << 1;
        a = a ^ b;  // add
        b = carry;
    }


    return a;
}

int main() {
    // example 1
    // output = 3
    // int a = 1;
    // int b = 2;

    // example 2
    // output = 5
    int a = 2;
    int b = 3;

    printf("%d ", getSum(a, b));

    return 0;
}
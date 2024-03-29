#include <stdio.h>

double myPow(double x, int n) {
    double res = 1;
    int tem = n / 2;

    if(n < 0) {
        x = 1 / x;
        tem = -tem;
    }

    if(n & 1)  res = x;

    while(tem != 0) {
        x *= x;
        if(tem & 1)  res *= x;
        tem /= 2;
    }

    return res;
}

void main() {
    // example 1
    // output = 1024.00000
    // float x = 2.00000;
    // int n = 10;

    // example 2
    // output = 9.26100
    // float x = 2.10000;
    // int n = 3;

    // example 3
    // output = 0.25000
    float x = 2.00000;
    int n = -2;

    printf("%f \n", myPow(x, n));
}
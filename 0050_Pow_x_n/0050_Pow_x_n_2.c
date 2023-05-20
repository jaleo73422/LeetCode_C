#include <stdio.h>

double myPow(double x, int n) {
    double res = 1;
    double x_exp;
    int tem = n;

    tem /= 2;

    if(n < 0) {
        x = 1 / x;
        tem = -tem;
    }

    x_exp = x;
    if(n & 1)  res = x;

    while(tem != 0) {
        x_exp *= x_exp;
        if(tem & 1)  res *= x_exp;
        tem /= 2;        
    }

    return res;
}

int main() {
    // example 1
    // output = 1024.00000
    // int x = 2.00000;
    // int n = 10;

    // example 2
    // output = 9.26100
    // int x = 2.10000;
    // int n = 3;

    // example 3
    // output = 0.25000
    int x = 2.00000;
    int n = -2;

    printf("%f \n", myPow(x, n));
    return 0;
}
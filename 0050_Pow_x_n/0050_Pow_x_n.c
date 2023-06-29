#include <stdio.h>

double myPow(double x, int n) {
    if(n == 0)  return 1;
    if(n == 1)  return x;

    int p = n / 2;

    if(n < 0) {
        p = -p;
        x = 1 / x;
    }

    double res = myPow(x, p);
    
    if(n % 2 == 0)  return res * res;
    
    return res * res * x;
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
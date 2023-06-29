#include <stdio.h>

double helper(double x, long int power) {
    if(power == 0)  return 1;
    if(power == 1)  return x;
    
    double base = 1;
    if(power % 2 == 1)  base = x;
    
    double tem = helper(x, power / 2);
    
    return tem * tem * base;
}

double myPow(double x, int n) {
    long int p = n;

    if(n < 0) {
        p = -p;
        x = 1 / x;
    }
    
    return helper(x, p);
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
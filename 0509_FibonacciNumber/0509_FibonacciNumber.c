#include <stdio.h>

int fib(int n) {
    if(n == 0)  return 0;
    if(n == 1)  return 1;

    return fib(n - 1) + fib(n - 2);
}

void main() {
    // example 1
    // output = 1
    // int n = 2;

    // example 2
    // output = 2
    // int n = 3;

    // example 3
    // output = 3
    // int n = 4;

    // example 4
    // output = 0
    int n = 0;

    printf("%d \n", fib(n));
}
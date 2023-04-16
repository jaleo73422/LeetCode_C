#include <stdio.h>

int fib(int n){
    if(n == 0)  return 0;
    if(n == 1)  return 1;

    int a = 0, b = 1;

    for(int i = 0; i < n - 1; i++) {
        int tem = b;
        b += a;
        a = tem;
    }

    return b;
}

int main() {
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

    return 0;
}
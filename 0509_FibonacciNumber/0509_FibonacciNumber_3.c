#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n == 0)  return 0;
    
    int* dp = (int*) calloc(n + 1, sizeof(int));
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
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
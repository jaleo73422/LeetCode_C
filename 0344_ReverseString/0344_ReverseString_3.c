#include <stdio.h>

void helper(char* s, int left, int right) {
    if (left >= right)  return ;
    
    char tem = s[left];
    s[left] = s[right];
    s[right] = tem;

    helper(s, left + 1, right - 1);
}

void reverseString(char* s, int sSize) {
    helper(s, 0, sSize - 1);
}

void main() {
    // example 1
    // output = olleh
    // int n = 5;
    // char s[] = "hello";

    // example 2
    // output = hannaH
    int n = 6;
    char s[] = "Hannah";

    reverseString(s, n);

    for(int i = 0; i < n; i++)
        printf("%c", s[i]);
    
    printf("\n");
}
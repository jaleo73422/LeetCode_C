#include <stdio.h>

void swap(char* a, char* b) {
    char tem = *a;
    *a = *b;
    *b = tem;
}

void reverseString(char* s, int sSize){
    for(int i = 0; i < sSize / 2; i++)
        swap(&s[i], &s[sSize - 1 - i]);
}

int main() {
    // example 1
    // output = olleh
    // int n = 5;
    // char s[n] = "hello";

    // example 2
    // output = hannaH
    int n = 6;
    char s[n] = "Hannah";

    reverseString(s, n);
    for(int i = 0; i < n; i++) {
        printf("%c", s[i]);
    }
    
    printf("\n");

    return 0;
}
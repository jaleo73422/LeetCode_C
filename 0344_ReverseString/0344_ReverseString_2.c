#include <stdio.h>

void reverseString(char* s, int sSize){
    int left = 0, right = sSize - 1;

    while (left < right) {
        char temp = s[left];
        
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
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
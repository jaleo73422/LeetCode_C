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
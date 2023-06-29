#include <stdio.h>
#include <string.h>

bool isPalindrome(char* s) {
    int sSize = strlen(s);
    int vSize = 0;
    char valid[sSize];

    for(int i = 0; i < sSize; i++) {
        if(48 <= s[i] && s[i] <= 57)
            valid[vSize++] = s[i];
        if((65 <= s[i] && s[i] <= 90) || (97 <= s[i] && s[i]  <= 122))
            valid[vSize++] = s[i] - 96 > 0 ? s[i] : s[i] + 32;
    }

    for(int i = 0; i < vSize / 2; i++)
        if(valid[i] != valid[vSize - 1 - i])
            return 0;

    return 1;
}

void main() {
    // example 1
    // output = true
    // char s[] = "A man, a plan, a canal: Panama";

    // example 2
    // output = false
    // char s[] = "race a car";

    // example 3
    // output = true
    // char s[] = " ";

    // example 4
    // output = false
    char s[] = "0P";

    printf("%d \n", isPalindrome(s));
}
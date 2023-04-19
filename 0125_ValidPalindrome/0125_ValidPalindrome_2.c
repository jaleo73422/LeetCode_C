#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s){
    int sSize = strlen(s);
    int i = 0, j = sSize - 1;
    
    while (i < j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }

    return true;
}

int main() {
    // example 1
    // output = true
    // char s[] = "A man, a plan, a canal: Panama";

    // example 2
    // output = false
    // char s[] = "race a car";

    // example 3
    // output = true
    char s[] = " ";

    // example 4
    // output = false
    // char s[] = "0P";

    printf("%d \n", isPalindrome(s));

    return 0;
}
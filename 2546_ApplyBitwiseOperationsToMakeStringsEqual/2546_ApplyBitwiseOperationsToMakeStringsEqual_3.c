#include <stdio.h>
#include <stdbool.h>

int find1(char* s) {
    int count = 0;

    while(s[count] != '\0')
        if(s[count++] == '1')  return count;

    return -1;
}

bool makeStringsEqual(char* s, char* target) {
    return (find1(s) != -1) == (find1(target) != -1);
}

void main() {
    // example 1
    // output = true
    // char s[] = "1010";
    // char target[] = "0110";

    // example 2
    // output = false
    // char s[] = "11";
    // char target[] = "00";

    // example 3
    // output = false
    // char s[] = "00100";
    // char target[] = "00000";

    // example 4
    // output = false
    // char s[] = "001000";
    // char target[] = "000100";

    // example 5
    // output = true
    // char s[] = "1110110";
    // char target[] = "1110100";

    // example 6
    // output = true
    char s[] = "000000";
    char target[] = "000000";

    printf("%d \n", makeStringsEqual(s, target));
}
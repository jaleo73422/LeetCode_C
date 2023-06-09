#include <stdio.h>
#include <stdbool.h>

bool contain1(char* s) {
    while(*s != '\0') {
        if(*s == '1')  return true;
        s++;
    }

    return false;
}

bool makeStringsEqual(char* s, char* target) {
    char* ptr_s = s, *ptr_target = target;
    
    while(*ptr_s == *ptr_target && *ptr_s != '\0') {
        ptr_s++;
        ptr_target++;
    }

    if(*ptr_s == '\0')  return true;
    else  return contain1(s) && contain1(target);
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
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int sSize = strlen(s);
    char stack[sSize];
    int current = 0;

    for(int i = 0; i < sSize; i++) {
        if(current == 0)
            stack[current++] = s[i];
        else {
            if(s[i] - stack[current - 1] == 1 || s[i] - stack[current - 1] == 2)
                current--;
            else  stack[current++] = s[i];
        }
    }

    return current == 0;
}

void main() {
    // example 1
    // output = true
    // char s[] = "()";

    // example 2
    // output = true
    // char s[] = "()[]{}";

    // example 3
    // output = false
    // char s[] = "(]";

    // example 4
    // output = true
    char s[] = "{[]}";

    printf("%d \n", isValid(s));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return *(char*) a - *(char*) b;
}

bool isAnagram(char* s, char* t){
    int sSize = strlen(s), tSize = strlen(t);

    if(sSize != tSize)  return 0;

    qsort(s, sSize, sizeof(char), cmp);
    qsort(t, tSize, sizeof(char), cmp);

    return strcmp(s, t) == 0;
}

void main() {
    // example 1
    // output = true
    // char s[] = "anagram";
    // char t[] = "nagaram";

    // example 2
    // output = false
    // char s[] = "rat";
    // char t[] = "car";

    // example 3
    // output = false
    char s[] = "rat";
    char t[] = "tare";

    printf("%d \n", isAnagram(s, t));
}
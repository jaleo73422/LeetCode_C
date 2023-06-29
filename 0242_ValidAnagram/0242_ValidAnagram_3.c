#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int sSize = strlen(s), tSize = strlen(t);

    if(sSize != tSize)  return 0;

    int hash_s[26] = {0};
    int hash_t[26] = {0};

    for(int i = 0; i < sSize; i++) {
        hash_s[s[i] - 'a']++;
        hash_t[t[i] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++)
        if(hash_s[i] != hash_t[i])
            return 0;

    return 1;
}

void main() {
    // example 1
    // output = true
    char s[] = "anagram";
    char t[] = "nagaram";

    // example 2
    // output = false
    // char s[] = "rat";
    // char t[] = "car";

    // example 3
    // output = false
    // char s[] = "rat";
    // char t[] = "tare";

    printf("%d \n", isAnagram(s, t));
}
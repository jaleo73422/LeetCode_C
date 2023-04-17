#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t){
    int sSize = strlen(s), tSize = strlen(t);

    if(sSize != tSize)  return 0;

    int hash[26] = {0};

    for(int i = 0; i < sSize; i++)
        hash[s[i] - 'a']++;
    
    for(int i = 0; i < tSize; i++) {
        hash[t[i] - 'a']--;

        if(hash[t[i] - 'a'] < 0)
            return 0;
    }

    return 1;
}

int main() {
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

    return 0;
}
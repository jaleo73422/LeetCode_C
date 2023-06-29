#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int length = 0;
    struct ListNode* curr = head;
    
    while(curr) {
        length++;
        curr = curr -> next;
    }
    
    int baseCount = length / k;
    int extraCount = length % k;
    
    *returnSize = k;
    struct ListNode** result = (struct ListNode**) malloc(sizeof(struct ListNode*) * k);
    
    curr = head;
    
    for(int i = 0; i < k; i++) {
        result[i] = curr;
        
        int count = baseCount;
        if(extraCount > 0) {
            count++;
            extraCount--;
        }
        
        for(int j = 0; j < count - 1; j++)
            curr = curr -> next;
        
        if(curr) {
            struct ListNode* nextNode = curr -> next;
            curr -> next = NULL;
            curr = nextNode;
        }
    }
    
    return result;
}

void main() {
}
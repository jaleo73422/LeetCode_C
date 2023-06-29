#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int get_length(struct ListNode* node) {
    if(!node)  return 0;
    return (1 + get_length(node -> next));
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int* length = calloc(k, sizeof(int));
    struct ListNode** result_node = (struct ListNode**) malloc(sizeof (struct ListNode*) * k);
    memset(result_node, 0, sizeof(struct ListNode*) * k);
    
    if(!head)  return result_node;
        
    struct ListNode* last_node;
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));

    dummy -> next = head;

    int llSizes = get_length(head);
    
    for(int i = 0; i < llSizes; i++)
        length[i % k]++;

    for(int i = 0; i < k; i++) {
        last_node = dummy;

        for(int j = 0; j < length[i]; j++)
            last_node = last_node -> next;

        result_node[i] = dummy -> next;

        dummy -> next = last_node -> next;
        last_node -> next = NULL;
    }
    
    *returnSize = k;
    
    return result_node;
}

void main() {
}
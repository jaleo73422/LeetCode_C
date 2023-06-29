#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 -> val += l2 -> val;
    
    int carry = l1 -> val / 10;
    struct ListNode* current = l1;
    current -> val %= 10;

    while(l2 -> next != NULL) {
        if(current -> next == NULL) {
            struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
            new_node -> val = 0;
            new_node -> next = NULL;
            current -> next = new_node;
        }

        current = current -> next;
        l2 = l2 -> next;

        current -> val += l2 -> val + carry;
        carry = current -> val / 10;
        current -> val %= 10;
    }

    while(carry != 0) {
        if(current -> next == NULL) {
            struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
            new_node -> val = 0;
            new_node -> next = NULL;
            current -> next = new_node;
        }

        current = current -> next;
        (current -> val) += carry;
        carry = current -> val / 10;
        current -> val %= 10;
    }
    
    return l1;
}

void main() {
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;

    while(l1 != NULL || l2 != NULL) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        int v1 = l1 == NULL ? 0 : l1 -> val;
        int v2 = l2 == NULL ? 0 : l2 -> val;

        new_node -> val = (carry + v1 + v2) % 10;
        carry = (carry + v1 + v2) / 10;

        current -> next = new_node;

        if(l1) l1 = l1 -> next;
        if(l2) l2 = l2 -> next;
        current = current -> next;
    }

    if(carry != 0) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

        new_node -> val = carry;
        current -> next = new_node;
        current = current -> next;
    }

    current -> next = NULL;

    return dummy -> next;
}

int main() {
   return 0;
}
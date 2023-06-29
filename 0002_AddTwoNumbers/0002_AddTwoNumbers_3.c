#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    int sum = 0;
    
    while(l1 || l2 || sum) {
        sum += (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
        if(l1) l1 = l1 -> next;
        if(l2) l2 = l2 -> next;

        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node -> val = sum % 10;

        current -> next = new_node;
        sum /= 10;
        current = current -> next;
    }

    current -> next = NULL;

    return dummy.next;
}

void main() {
}
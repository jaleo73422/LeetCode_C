#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)  return head;

    struct ListNode* slow_node = head;
    struct ListNode* fast_node = head;

    while(fast_node != NULL && fast_node -> next != NULL) {
        slow_node = slow_node -> next;
        fast_node = fast_node -> next -> next;

        if(slow_node == NULL)
            return slow_node;

        if(slow_node == fast_node) {
            fast_node = head;

            while(slow_node != fast_node) {
                slow_node = slow_node -> next;
                fast_node = fast_node -> next;
            }

            return slow_node;
        }
    }

    return NULL;
}

void main() {
}
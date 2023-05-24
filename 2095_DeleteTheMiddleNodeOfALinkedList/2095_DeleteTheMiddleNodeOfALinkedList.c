#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head){
    if(head -> next == NULL)  return NULL;

    struct ListNode* slow_node = head;
    struct ListNode* fast_node = head;
    struct ListNode* pre_node;

    while(fast_node != NULL && fast_node -> next != NULL) {
        pre_node = slow_node;
        slow_node = slow_node -> next;
        fast_node = fast_node -> next -> next;
    }

    pre_node -> next = slow_node -> next;
    free(slow_node);

    return head;
}

int main() {
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* cur_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* dummy = cur_node;

    while(head1 != NULL && head2 != NULL) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

        if(head1 -> val < head2 -> val) {
            new_node -> val = head1 -> val;
            head1 = head1 -> next;
        } else {
            new_node -> val = head2 -> val;
            head2 = head2 -> next;
        }
        
        cur_node -> next = new_node;
        cur_node = cur_node -> next;
    }

    cur_node -> next = (head1 != NULL) ? head1 : head2;

    return dummy -> next;
}


struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)  return head;

    struct ListNode* slow_node = head;
    struct ListNode* fast_node = head -> next;

    while(fast_node != NULL && fast_node -> next != NULL) {
        slow_node = slow_node -> next;
        fast_node = fast_node -> next -> next;
    }

    struct ListNode* head2 = slow_node -> next;
    slow_node -> next = NULL;

    struct ListNode* new1 = sortList(head);
    struct ListNode* new2 = sortList(head2);

    return merge(new1, new2);
}

void main() {
}
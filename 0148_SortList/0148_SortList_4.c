#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {    
    struct ListNode dummy;
    struct ListNode* tail_node = &dummy;

    while(head1 != NULL && head2 != NULL) {
        if(head1 -> val > head2 -> val) {
            // swap
            struct ListNode* tem_node = head1;
            head1 = head2;
            head2 = tem_node;
        }

        tail_node -> next = head1;
        head1 = head1 -> next;
        tail_node = tail_node -> next;
    }

    if(head1 != NULL)
        tail_node -> next = head1;
    
    if(head2 != NULL)
        tail_node -> next = head2;

    return dummy.next;
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

    return merge(sortList(head), sortList(head2));
}

void main() {
}
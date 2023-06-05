#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    if(head1 == NULL)  return head2;
    if(head2 == NULL)  return head1;
    
    struct ListNode* sorted_node;
    
    if(head1 -> val < head2 -> val) {
        sorted_node = head1;
        sorted_node -> next = merge(head1 -> next, head2);
    }else {
        sorted_node = head2;
        sorted_node -> next = merge(head1, head2 -> next);
    }
    
    return sorted_node;
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
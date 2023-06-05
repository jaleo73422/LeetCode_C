#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* cur_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* dummy = cur_node;
    struct ListNode* slide1 = head1;

    while(slide1 != NULL && head2 != NULL) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

        if(slide1 -> val < head2 -> val) {
            new_node -> val = slide1 -> val;
            slide1 = slide1 -> next;
        } else {
            new_node -> val = head2 -> val;
            head2 = head2 -> next;
        }
        
        cur_node -> next = new_node;
        cur_node = cur_node -> next;
    }

    if(slide1 == head1) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node -> val = slide1 -> val;
        slide1 = slide1 -> next;
        cur_node -> next = new_node;
        cur_node = cur_node -> next;
    }
    cur_node -> next = (slide1 != NULL) ? slide1 : head2;

    head1 -> val = dummy -> next -> val;
    head1 -> next = dummy -> next -> next;
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

    sortList(head);
    sortList(head2);
    merge(head, head2);

    return head;
}

void main() {
}
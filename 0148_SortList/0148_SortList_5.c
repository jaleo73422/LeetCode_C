#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* split(struct ListNode* head, int step) {
    if(head == NULL)  return head;

    for(int i = 1; head -> next != NULL && i < step; i++)
        head = head -> next;

    struct ListNode* head2 = head -> next;
    head -> next = NULL;

    return head2;
}

struct ListNode* merge(struct ListNode* tail, struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* sorted_node = tail;

    while(head1 != NULL && head2 != NULL) {
        if(head1 -> val < head2 -> val) {
            sorted_node -> next = head1;
            head1 = head1 -> next;
        }else {
            sorted_node -> next = head2;
            head2 = head2 -> next;
        }

        sorted_node = sorted_node -> next;
    }

    sorted_node -> next = (head1 != NULL) ? head1 : head2;

    while(sorted_node -> next != NULL)
        sorted_node = sorted_node -> next;

    return sorted_node;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    int length = 1;
    while(head = head -> next)
        length++;

    for(int step = 1; step < length; step *= 2) {
        struct ListNode* cur_node = dummy.next;
        struct ListNode* tail = &dummy;

        while(cur_node != NULL) {
            struct ListNode* head1 = cur_node;
            struct ListNode* head2 = split(head1, step);
            cur_node = split(head2, step);
            tail = merge(tail, head1, head2);
        }
    }

    return dummy.next;
}

void main() {
}
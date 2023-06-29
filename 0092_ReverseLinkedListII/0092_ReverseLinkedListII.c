#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left == right)  return head;

    struct ListNode* new_head = head;
    struct ListNode* front_tail = (struct ListNode*) malloc(sizeof(struct ListNode));

    front_tail -> next = new_head;

    for(int i = 1; i < left; i++) {
        front_tail = front_tail -> next;
        new_head = new_head -> next;
    }

    struct ListNode* pre_node = NULL;
    struct ListNode* current_node = new_head;
    struct ListNode* next_node = NULL;
    struct ListNode* reverse_tail = current_node;

    for(int i = 1; i <= right - left + 1; i++) {
        next_node = current_node -> next;
        current_node -> next = pre_node;
        pre_node = current_node;
        current_node = next_node;
    }

    reverse_tail -> next = current_node;
    front_tail -> next = pre_node;

    if(left == 1)  return pre_node;
    else  return head;
}

void main() {
}
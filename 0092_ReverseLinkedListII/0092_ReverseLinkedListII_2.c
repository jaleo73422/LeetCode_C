#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left == right)  return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* pre_node = &dummy;

    for(int i = 1; i < left; i++)
        pre_node = pre_node -> next;

    struct ListNode* current_node = pre_node -> next;
    struct ListNode* next_node = NULL;

    for(int i = 0; i < right - left; i++) {
        next_node = current_node -> next;
        current_node -> next = next_node -> next;
        next_node -> next = pre_node -> next;
        pre_node -> next = next_node;
    }

    return dummy.next;
}

int main() {
   return 0;
}
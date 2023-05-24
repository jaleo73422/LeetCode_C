#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)  return head;

    struct ListNode* odd_node = head;
    struct ListNode* even_node = head -> next;
    struct ListNode* even_head_node = even_node;

    while(odd_node -> next != NULL && even_node -> next != NULL) {
        odd_node -> next = odd_node -> next -> next;
        even_node -> next = even_node -> next -> next;
        
        odd_node = odd_node -> next;
        even_node = even_node -> next;
    }

    odd_node -> next = even_head_node;

    return head;
}

int main() {
    return 0;
}
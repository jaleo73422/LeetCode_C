#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)  return head;

    struct ListNode* odd_node = head;
    struct ListNode* even_node = head -> next;
    struct ListNode* even_head_node = even_node;
    struct ListNode* tem_node = even_node -> next;
    int oddEven = 1;

    while(tem_node != NULL) {
        if(oddEven) {
            odd_node -> next = tem_node;
            odd_node = odd_node -> next;
        } else {
            even_node -> next = tem_node;
            even_node = even_node -> next;
        }

        oddEven = !oddEven;
        tem_node = tem_node -> next;
    }

    even_node -> next = NULL;
    odd_node -> next = even_head_node;

    return head;
}

void main() {
}
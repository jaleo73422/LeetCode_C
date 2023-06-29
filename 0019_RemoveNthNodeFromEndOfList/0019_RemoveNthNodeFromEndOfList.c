#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* tem_node = head;
    struct ListNode* pre_node = head;
    int llSizes = 0;

    while(tem_node != NULL) {
        llSizes++;
        tem_node = tem_node -> next;
    }

    if(n == llSizes)  return head -> next;

    for(int  i = 1; i < llSizes - n; i++)
        pre_node = pre_node -> next;

    tem_node = pre_node -> next;
    pre_node -> next = tem_node -> next;
    free(tem_node);

    return head;
}

void main() {
}
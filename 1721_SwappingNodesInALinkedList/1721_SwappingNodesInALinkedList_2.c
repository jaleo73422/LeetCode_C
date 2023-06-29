#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* cur_node = head;
    struct ListNode* first_node;
    struct ListNode* second_node;
    int llSizes = 0;

    while(cur_node != NULL) {
        llSizes++;
        cur_node = cur_node -> next;
    }

    cur_node = head;

    for(int i = 1; i <= llSizes; i++) {
        if(i == k)
            first_node = cur_node;

        if(i == llSizes - k + 1)
            second_node = cur_node;

        cur_node = cur_node -> next;
    }

    int tem = first_node -> val;
    first_node -> val = second_node -> val;
    second_node -> val = tem;

    return head;
}

void main() {
}
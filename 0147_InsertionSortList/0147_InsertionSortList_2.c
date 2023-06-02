#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head -> next == NULL)
        return head;

    struct ListNode* dummy = (struct ListNode*) malloc (sizeof(struct ListNode));
    dummy -> val = -5001;
    dummy -> next = NULL;

    struct ListNode* cur_node = head;

    while(cur_node != NULL) {
        struct ListNode* pre_node = dummy;

        while(pre_node -> next != NULL && pre_node -> next -> val < cur_node -> val)
            pre_node = pre_node -> next;

        struct ListNode* next_node = cur_node -> next;
        cur_node -> next = pre_node -> next;
        pre_node -> next = cur_node;
        cur_node = next_node;
    }

    struct ListNode* sorted_head = dummy -> next;
    free(dummy);

    return sorted_head;
}

void main() {
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* replace_node;
    struct ListNode* cur_node = head;
    int replace_val;
    int llSizes = 0;
    int flag = 0;

    while(cur_node != NULL) {
        llSizes++;
        cur_node = cur_node -> next;
    }

    cur_node = head;

    for(int i = 1; i <= llSizes; i++) {
        if(i == k || i == llSizes - k + 1) {
            if(flag) {  // i == llSizes - k + 1
                replace_node -> val = cur_node -> val;
                cur_node -> val = replace_val;
                break;
            } else {  // i == k
                flag = 1;
                replace_val = cur_node -> val;
                replace_node = cur_node;
            }
        }

        cur_node = cur_node -> next;
    }

    return head;
}

void main() {
}
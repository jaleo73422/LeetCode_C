#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* replace_node;
    struct ListNode* tem_node = head;
    int replace_val;
    int llSizes = 0;
    int flag = 0;

    while(tem_node != NULL) {
        llSizes++;
        tem_node = tem_node -> next;
    }

    tem_node = head;

    for(int i = 1; i <= llSizes; i++) {
        if(i == k || i == llSizes - k + 1) {
            if(flag) {
                replace_node -> val = tem_node -> val;
                tem_node -> val = replace_val;
                break;
            } else {
                flag = 1;
                replace_val = tem_node -> val;
                replace_node = tem_node;
            }
        }

        tem_node = tem_node -> next;
    }

    return head;
}

int main() {
    return 0;
}
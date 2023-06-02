#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head -> next == NULL)  return head;

    struct ListNode* reverse_head = head;
    struct ListNode* cur_node = head -> next;
    reverse_head -> next = NULL;

    struct ListNode* insert_node;

    while(cur_node != NULL) {
        insert_node = cur_node;
        cur_node = cur_node -> next;

        // (1)
        if(reverse_head -> val <= insert_node -> val) {
            insert_node -> next = reverse_head;
            reverse_head = insert_node;
            continue;
        }

        struct ListNode* tem_node = reverse_head;

        // (2)
        while(tem_node -> next != NULL) {
            if(tem_node -> val > insert_node -> val && insert_node -> val >= tem_node -> next -> val) {
                insert_node -> next = tem_node -> next;
                tem_node -> next = insert_node;
                break;
            }
            tem_node = tem_node -> next;
        }

        // (3)
        if(tem_node -> next == NULL) {
            insert_node -> next = tem_node -> next;
            tem_node -> next = insert_node;
        }
    }

    struct ListNode* fin_pre = NULL;
    struct ListNode* fin_cur = reverse_head;
    struct ListNode* fin_next = NULL;

    while(fin_cur != NULL) {
        fin_next = fin_cur -> next;
        fin_cur -> next = fin_pre;
        fin_pre = fin_cur;
        fin_cur = fin_next;
    }

    return fin_pre;
}

void main() {
}
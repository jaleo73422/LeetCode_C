#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    int llSize = 1, idx = 1;
    int group_end = 1, group_size = 1;
    struct ListNode* cur_node = head;
    struct ListNode* pre_node, * rev_tail;
    struct ListNode* tem_pre = NULL, * tem_next;

    while(cur_node = cur_node -> next)
        llSize++;
    
    cur_node = head;
    
    while(cur_node != NULL) {
        // reverse in even group
        if(group_size % 2 == 0) {
            if(idx <= group_end) {
                tem_next = cur_node -> next;
                cur_node -> next = tem_pre;
                tem_pre = cur_node;
                cur_node = tem_next;

                // reverse done, connect reverse linked list
                if(idx == group_end) {
                    pre_node -> next = tem_pre;
                    rev_tail -> next = tem_next;
                }
            }
        }

        // group is end, prepare to next group
        if(idx == group_end) {
            // pre-act for reverse
            if(group_size % 2 == 0) {  // if last group size is even 
                                       // and behind even size group
                pre_node = rev_tail;
                rev_tail = tem_next;
            } else {
                pre_node = cur_node;
                rev_tail = pre_node -> next;
                cur_node = cur_node -> next;
            }

            // prepare to next group
            group_size++;
            // decide to last group size
            group_size = llSize - 1 < group_size ? llSize - 1 : group_size;
            group_end = idx + group_size;
        // odd group before end of group
        } else if(group_size % 2 == 1)
            cur_node = cur_node -> next;

        idx++;
        llSize--;
    }

    return head;
}

void main() {
}
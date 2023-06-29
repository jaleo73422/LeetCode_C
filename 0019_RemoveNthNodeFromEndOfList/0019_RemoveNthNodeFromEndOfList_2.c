#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;

    for(int i = 0; i <= n; i++)
        second = second -> next;
    
    while(second) {
        first = first -> next;
        second = second -> next;
    }

    struct ListNode* tem = first -> next;
    first -> next = tem -> next;
    free(tem);
    
    return dummy.next;
}

void main() {
}
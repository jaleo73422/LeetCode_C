#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* current = head;
    
    while(current != NULL && current -> next != NULL) {
        int tem = current -> val;
		
        current -> val = current -> next -> val;
        current -> next -> val = tem;
        current = current -> next -> next;
    }

    return head;
}

int main() {
    return 0;
}
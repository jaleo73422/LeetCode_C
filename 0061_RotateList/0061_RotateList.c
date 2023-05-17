#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)  return NULL;

    struct ListNode* last = head;
    struct ListNode* new_head = head;
    struct ListNode* secLast;
    int llSize = 0;
    int rotateTime;

    while(last != NULL) {
        llSize++;
        last = last -> next;
    }

    rotateTime = k % llSize;

    for(int i = 0; i < rotateTime; i++) {
        secLast = new_head;
        last = new_head -> next;

        while(last -> next != NULL) {
            secLast = secLast -> next;
            last = last -> next;
        }

        last -> next = new_head;
        new_head = last;
        secLast -> next = NULL;
    }

    return new_head;
}

int main() {
   return 0;
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)  return NULL;

    struct ListNode* tem = head;
    struct ListNode* new = head;
    struct ListNode* last;
    int llSize = 0;
    int rotateTime;

    while(tem != NULL) {
        llSize++;
        tem = tem -> next;
    }

    rotateTime = k % llSize;

    for(int i = 0; i < rotateTime; i++) {
        last = new;
        tem = new -> next;
        while(tem -> next != NULL) {
            last = last -> next;
            tem = tem -> next;
        }
        tem -> next = new;
        new = tem;
        last -> next = NULL;
    }

    return new;
}

int main() {
   return 0;
}
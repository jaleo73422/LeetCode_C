#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head || !(head -> next) || k == 0)  return head;

    struct ListNode* tail = head;
    struct ListNode* new_tail = head;
    struct ListNode* new_head;
    int llSize = 1;
    int rotateTime;

    while(tail -> next != NULL) {
        llSize++;
        tail = tail -> next;
    }

    rotateTime = k % llSize;

    if(rotateTime == 0)  return head;

    for(int i = 1; i < llSize - rotateTime; i++)
        new_tail = new_tail -> next;

    new_head = new_tail -> next;
    new_tail -> next = NULL;
    tail -> next = head;

    return new_head;
}

int main() {
   return 0;
}
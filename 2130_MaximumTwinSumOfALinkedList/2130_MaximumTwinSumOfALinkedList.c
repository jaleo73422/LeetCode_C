#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head) {
    struct ListNode* list1 = head;
    struct ListNode* list2;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int max = head -> val;

    while(fast != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    struct ListNode* pre = NULL;
    struct ListNode* current = slow;
    struct ListNode* next;

    while(current != NULL) {
        next = current -> next;
        current -> next = pre;
        pre = current;
        current = next;
    }

    list2 = pre;

    while(list2 != NULL) {
        if(max < list1 -> val + list2 -> val)
            max = list1 -> val + list2 -> val;

        list1 = list1 -> next;
        list2 = list2 -> next;
    }

    return max;
}

void main() {
}
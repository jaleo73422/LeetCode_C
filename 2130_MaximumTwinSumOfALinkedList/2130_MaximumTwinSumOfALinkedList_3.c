#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head) {
    struct ListNode* list1 = head;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int llSize = 1;
    int max = head -> val;
    int top = -1;

    while(fast != NULL) {
        llSize++;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    llSize--;

    int list2[llSize];

    while(slow != NULL) {
        list2[++top] = slow -> val;
        slow = slow -> next;
    }

    for(int i = 0; i < llSize; i++) {
        int tem = list2[top--];

        if(max < tem + list1 -> val)
            max = tem + list1 -> val;

        list1 = list1 -> next;
    }

    return max;
}

void main() {
}
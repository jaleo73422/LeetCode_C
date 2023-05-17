#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void stackPush(struct ListNode** head, int val) {
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

    new_node -> val = val;
    new_node -> next = NULL;

    if((*head) != NULL) {
        struct ListNode* last = *head;

        while(last -> next != NULL)
            last = last -> next;

        last -> next = new_node;
    } else  *head = new_node;
}

int stackPop(struct ListNode** head) {
    if((*head) -> next == NULL) {
        int tem = (*head) -> val;
        *head = NULL;
        return tem;
    }

    struct ListNode* secLast = *head;

    while(secLast -> next -> next != NULL)
        secLast = secLast -> next;

    int tem = secLast -> next -> val;
    free(secLast -> next);

    secLast -> next = NULL;

    return tem;
}


int pairSum(struct ListNode* head) {
    struct ListNode* list1 = head;
    struct ListNode* list2 = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int llSize = 1;
    int max = head -> val;

    while(fast != NULL) {
        llSize++;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    llSize--;

    while(slow != NULL) {
        stackPush(&list2, slow -> val);
        slow = slow -> next;
    }

    for(int i = 0; i < llSize; i++) {
        int tem = stackPop(&list2);

        if(max < tem + list1 -> val)
            max = tem + list1 -> val;

        list1 = list1 -> next;
    }

    return max;
}

int main() {
   return 0;
}
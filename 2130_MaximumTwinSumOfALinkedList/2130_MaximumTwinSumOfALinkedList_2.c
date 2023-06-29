#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = val;
    new_node -> next = NULL;
    
    return new_node;
}

void stackPush(struct Node** head, int val) {
    struct Node* new_node = newNode(val);

    new_node -> next = *head;
    *head = new_node;
}

int stackPop(struct Node** head) {    
    struct Node* tem_node = *head;
    *head = (*head) -> next;
    
    int popVal = tem_node -> data;
    free(tem_node);
    
    return popVal;
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

void main() {
}
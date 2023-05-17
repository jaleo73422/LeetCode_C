#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if(!head || !(head -> next))  return head;

	struct ListNode dummy;
	struct ListNode* pre = &dummy;
	
	pre -> next = head;

	while(pre -> next != NULL && pre -> next -> next != NULL) {
		struct ListNode* first = pre -> next;
		struct ListNode* second = first -> next;

		pre -> next = second;
		first -> next = second -> next;
		second -> next = first;

		pre = first;
	}

	return dummy.next;
}

int main() {
	return 0;
}
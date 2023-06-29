#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int llSizes = 0;
    struct ListNode* count_node = head;
    struct ListNode** result_node = (struct ListNode**) malloc(sizeof(struct ListNode*) * k);
    int idx;

    while(count_node != NULL) {
        llSizes++;
        count_node = count_node -> next;
    }

    struct ListNode* tem_node;
    struct ListNode* slide_node = head;

    if(llSizes < k) {
        idx = 0;

        for(int i = 0; i < llSizes; i++) {
            tem_node = slide_node;
            result_node[idx++] = tem_node;
            slide_node = slide_node -> next;
            tem_node -> next = NULL;
        }

        for(int i = 0; i < k - llSizes; i++)
            result_node[idx++] = NULL;
    }else if(llSizes == k) {
        for(int i = 0; i < k; i++) {
            tem_node = slide_node;
            result_node[i] = tem_node;
            slide_node = slide_node -> next;
            tem_node -> next = NULL;
        }
    }else {
        int times = llSizes % k;

        if(times == 0) {
            for(int i = 0; i < k; i++) {
                tem_node = slide_node;
                result_node[i] = slide_node;

                for(int j = 0; j < llSizes / k - 1; j++)
                    slide_node = slide_node -> next;

                struct ListNode* last_node = slide_node;
                slide_node = slide_node -> next;
                last_node -> next = NULL;
            }
        } else {
            idx = 0;

            for(int i = 0; i < times; i++) {
                tem_node = slide_node;
                result_node[idx++] = slide_node;

                for(int j = 0; j < llSizes / k; j++)
                    slide_node = slide_node -> next;

                struct ListNode* last_node = slide_node;
                slide_node = slide_node -> next;
                last_node -> next = NULL;
            }

            for(int i = 0; i < k - times; i++) {
                tem_node = slide_node;
                result_node[idx++] = slide_node;

                for(int j = 0; j < llSizes / k - 1; j++)
                    slide_node = slide_node -> next;

                struct ListNode* last_node = slide_node;
                slide_node = slide_node -> next;
                last_node -> next = NULL;
            }
        }
    }

    *returnSize = k;

    return result_node;
}

void main() {
}
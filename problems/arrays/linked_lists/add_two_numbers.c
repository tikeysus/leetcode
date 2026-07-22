/*
Problem: add two numbers
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Initial idea:
Something like what I just did. Must devise a way of isolating digits. 

Final approach:

Complexity:
Time:
Space:

Mistakes / difficulties:
Carries.

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void addTwoNumbersRecursive(struct ListNode* l1, struct ListNode* l2, int carry, struct ListNode* acc) {
    int l1_val = 0;
    if (l1 != NULL) {
        l1_val = l1->val;
    }
    
    int l2_val = 0;
    if (l2 != NULL) {
        l2_val = l2->val;
    }
    
    int digit_sum_carry = l1_val + l2_val + carry;
    
    acc->val = digit_sum_carry % 10;
    int new_carry = digit_sum_carry / 10;
    
    struct ListNode* next_l1 = NULL;
    if (l1 != NULL) {
        next_l1 = l1->next;
    }
    
    struct ListNode* next_l2 = NULL;
    if (l2 != NULL) {
        next_l2 = l2->next;
    }
    
    if (next_l1 == NULL && next_l2 == NULL && new_carry == 0) {
        acc->next = NULL;
        return;
    }
    
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    acc->next = new_node;
    addTwoNumbersRecursive(next_l1, next_l2, new_carry, new_node);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    addTwoNumbersRecursive(l1, l2, 0, head);
    return head;
}
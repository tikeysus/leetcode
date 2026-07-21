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

struct ListNode* addTwoNumbersRecursive(struct ListNode* l1, struct ListNode* l2, int carry) {
    // Base case: both lists exhausted
    if (l1 == NULL && l2 == NULL) {
        if (carry == 0) return NULL;
        
        // Create node for final carry
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        return node;
    }
    
    // Extract values (0 if list is exhausted)
    int val1 = (l1 != NULL) ? l1->val : 0;
    int val2 = (l2 != NULL) ? l2->val : 0;
    
    // Calculate sum and new carry
    int digit_sum = val1 + val2 + carry;
    int digit = digit_sum % 10;
    int new_carry = digit_sum / 10;
    
    // Move to next nodes
    struct ListNode* next_l1 = (l1 != NULL) ? l1->next : NULL;
    struct ListNode* next_l2 = (l2 != NULL) ? l2->next : NULL;
    
    // Create current node and recursively build rest of list
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = digit;
    node->next = addTwoNumbersRecursive(next_l1, next_l2, new_carry);
    
    return node;
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumbersRecursive(l1, l2, 0);
}
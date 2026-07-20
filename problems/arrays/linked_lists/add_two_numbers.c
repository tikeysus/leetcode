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

long long linked_to_int(struct ListNode* l){
	long long acc = 0; 
	while (l != NULL){
		acc += l->val;
		if (l->next != NULL) { acc *= 10; }
		l = l->next; 
	}
	return acc; 
}

struct ListNode* int_to_linked(long long res) {
	long long res_copy = res; 

	struct ListNode *node_digit = (struct ListNode*)(malloc(sizeof(struct ListNode*))); 
	node_digit->next = NULL; 

	int i = 1; 
	while (res_copy != 0){
		int digit = (res % (10LL * i)) / i; 
		node_digit->val = digit; 

		struct ListNode *new_node = (struct ListNode*)(malloc(sizeof(struct ListNode*))); 
		new_node -> next = node_digit; 

		i *= 10; res_copy /= 10; 
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if (l1->val == 0) { return l2; }
	if (l2->val == 0) { return l1; }
	
	long long l1_int = linked_to_int(l1);
	long long l2_int = linked_to_int(l2);
	long long res = l2_int + l1_int; 
}
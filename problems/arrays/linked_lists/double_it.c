/*
Problem: double it
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Constraints:
The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

Initial idea:
Tail recursion. Don't allocate a node unless it's not needed. 

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

struct ListNode {
	int val;
	struct ListNode *next;
};

int doubleItRecursive(struct ListNode* head, struct ListNode* acc){
}

struct ListNode* doubleIt(struct ListNode* head){
	struct ListNode* acc = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* acc_head = acc; 
	int carry = doubleItRecursive(head, acc); 
	if (carry == 1){
		struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->val = 1; 
		new_node->next = acc_head; 
		return new_node; 
	}
	return acc_head; 
}